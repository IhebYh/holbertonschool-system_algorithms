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
	edge_t *srcEdge, *destEdge, *newSrcEdge, *newDestEdge;
	int failure = 0;

	if (!graph || !src || !dest)
		return (0);
	failure = get_edges_vertices(src, dest, srcVertex, destVertex, srcEdge,
				newSrcEdge, destEdge, newDestEdge, type, graph);
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
 * @srcVertex : source vertex
 * @destVertex : destination vertex
 * @srcEdge : source edge
 * @newSrcEdge : new source edge
 * @destEdge : destination edge
 * @newDestEdge : new destination edge
 * @type : edge type
 * Return: int
 */
int get_edges_vertices(const char *src, const char *dest, vertex_t *srcVertex,
					  vertex_t *destVertex, edge_t *srcEdge,
					  edge_t *newSrcEdge, edge_t *destEdge,
					  edge_t *newDestEdge, edge_type_t type, graph_t *graph)
{
	int failure = 0;
	vertex_t *currVertex;

	for (currVertex = graph->vertices; currVertex; currVertex = currVertex->next)
	{
		if (srcVertex && destVertex)
			break;
		if (!srcVertex && !strcmp(src, currVertex->content))
			srcVertex = currVertex;
		if (!destVertex && !strcmp(dest, currVertex->content))
			destVertex = currVertex;
	}
	if (!srcVertex || !destVertex)
		return (0);
	for (srcEdge = srcVertex->edges; srcEdge; srcEdge = srcEdge->next)
	{
		if (srcEdge->dest == destVertex)
		{
			failure = FAILED_SRC;
			break;
		}
	}
	if (failure == FAILED_SRC)
		return (0);
	for (destEdge = destVertex->edges; destEdge; destEdge = destEdge->next)
	{
		if (destEdge->dest == srcVertex)
		{
			failure = FAILED_DEST;
			break;
		}
	}
	return (failure);
}
