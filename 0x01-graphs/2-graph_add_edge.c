#include "graphs.h"

/**
 * graph_add_edge - adds edge to graph
 * @graph: pointer to graph object
 * @str: string value for new vertex
 * Return: 1 on success else 0
 */
int graph_add_edge(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *vertex;

	if (!graph || !str)
		return (NULL);
	vertex = graph->vertices;
	while (vertex)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		if (!vertex->next)
			break;
		vertex = vertex->next;
	}
	new_vertex = malloc(size(vertex_t));
	if (!new_vertex)
		return (NULL);
	new_vertex->content = strdup(str);
	if (!new_vertex->content)
	{
		free(new_vertex);
		return (NULL);
	}
	new_vertex->index = graph->nb_vertices++;
	if (vertex)
		vertex->next = new_vertex;
	else
		graph->vertices = new_vertex;
	return (new_vertex);
}
