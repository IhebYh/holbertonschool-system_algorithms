#include "graphs.h"

/**
 * graph_add_edge - adds edge to graph
 * @graph: pointer to graph object
 * @src: name of source vertex
 * @dest: name of destination vertex
 * @type: type of edge UNI/BI
 * Return: 1 on success else 0
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *firstVertex = NULL, *secondVertex = NULL;
	edge_t *firstEdge, *secondEdge;

	for ()
	/*
	TODO:
	- get the vertices
	- check the edges
	- alloc the edges and add the dest
	- return 1 on success else return 0
	*/
}