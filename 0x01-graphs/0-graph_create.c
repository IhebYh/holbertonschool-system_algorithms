#include "graphs.h"

/**
 * graph_create - allocates memory to store a graph_t structure,
 * and initializes its content.
 * Return: graph_t*
 */
graph_t *graph_create(void)
{
	graph_t *graph = NULL;

	graph = malloc(sizeof(graph_t));
	if (!graph)
		return (NULL);
	graph->vertices = NULL;
	graph->nb_vertices = 0;
	return (graph);
}
