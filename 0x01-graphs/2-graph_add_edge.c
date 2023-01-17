#include "graphs.h"

#define FAILED_SRC	1
#define FAILED_DEST	2


/**
 * graph_add_edge - adds edge to graph
 * @graph: pointer to graph object
 * @src: name of source vertex
 * @dest: name of destination vertex
 * @type: type of edge UNI/BI
 * Return: 1 on success else 0
 */
int graph_add_edge(graph_t *graph, const char *src,
				   const char *dest, edge_type_t type)
{
	vertex_t *srcVertex = NULL, *destVertex = NULL;
	edge_t *srcEdge = NULL, *destEdge = NULL, *newSrcEdge, *newDestEdge;
	int failure = 0;

	if (!graph || !src || !dest)
		return (0);
	failure = get_edges_vertices(src, dest, &srcVertex, &destVertex, &srcEdge,
				&destEdge, graph);
	if (failure == FAILED_DEST && type == BIDIRECTIONAL)
		return (0);
	newSrcEdge = malloc(sizeof(edge_t));
	if (!newSrcEdge)
	{
		free(newSrcEdge);
		return (0);
	}
	newDestEdge = malloc(sizeof(edge_t));
	if (!newDestEdge)
	{
		free(newDestEdge);
		return (0);
	}
	if (type == BIDIRECTIONAL)
	{
		srcVertex->nb_edges++;
		destVertex->nb_edges++;
		newDestEdge->dest = srcVertex;
		newSrcEdge->dest = destVertex;
		if (destEdge)
			destEdge->next = newDestEdge;
		else
			destVertex->edges = newDestEdge;
		if (srcEdge)
			srcEdge->next = newSrcEdge;
		else
			srcVertex->edges = newSrcEdge;
	}
	else
	{
		free(newDestEdge);
		srcVertex->nb_edges++;
		newSrcEdge->dest = destVertex;
		if (srcEdge)
			srcEdge->next = newSrcEdge;
		else
			srcVertex->edges = newSrcEdge;
	}
	return (1);
}

/**
 * edge_creator - creating an edge for the vertex
 * in consideration of the edge type
 * @srcVertex: source vertex
 * @destVertex: destination vertex
 * @srcEdge: source edge
 * @src: source
 * @destEdge: destination edge
 * @dest: destination
 * @graph: graph
 * Return: int
 */
int get_edges_vertices(const char *src, const char *dest, vertex_t **srcVertex,
					  vertex_t **destVertex, edge_t **srcEdge,
					  edge_t **destEdge, graph_t *graph)
{
	int failure = 0;
	vertex_t *currVertex;
	edge_t *src_e = NULL, *dest_e = NULL;
	vertex_t *src_v = NULL, *dest_v = NULL;

	for (currVertex = graph->vertices; currVertex; currVertex = currVertex->next)
	{
		if (src_v && dest_v)
			break;
		if (!src_v && !strcmp(src, currVertex->content))
			src_v = currVertex;
		if (!dest_v && !strcmp(dest, currVertex->content))
			dest_v = currVertex;
	}
	if (!src_v || !dest_v)
		return (0);
	for (src_e = src_v->edges; src_e; src_e = src_e->next)
	{
		if (src_e->dest == dest_v)
		{
			failure = FAILED_SRC;
			break;
		}
	}
	if (failure == FAILED_SRC)
		return (0);
	for (dest_e = dest_v->edges; dest_e; dest_e = dest_e->next)
	{
		if (dest_e->dest == src_v)
		{
			failure = FAILED_DEST;
			break;
		}
	}
	*destEdge = dest_e;
	*destVertex = dest_v;
	*srcEdge = src_e;
	*srcVertex = src_v;
	return (failure);
}
