#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t    *dest;
	struct edge_s   *next;
} edge_t;


/**
 * struct Node - node for queue/stack
 * @vertex: pointer to vertex
 * @depth: depth of this vertex
 * @next: pointer of next node in this list
 */
typedef struct Node
{
	vertex_t *vertex;
	size_t depth;
	struct Node *next;
} node_t;

/**
 * struct Queue - queue object
 * @head: pointer to head node
 * @tail: pointer to tail node
 * @size: size of queue
 */
typedef struct Queue
{
	node_t *head;
	node_t *tail;
	size_t size;
} queue_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t      index;
	char        *content;
	size_t      nb_edges;
	edge_t      *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
	size_t      nb_vertices;
	vertex_t    *vertices;
} graph_t;

graph_t *graph_create(void);
vertex_t *graph_add_vertex(graph_t *graph, const char *str);
int graph_add_edge(graph_t *graph, const char *src,
				   const char *dest, edge_type_t type);
int get_edges_vertices(const char *src, const char *dest, vertex_t **srcVertex,
					  vertex_t **destVertex, edge_t **srcEdge,
					  edge_t **destEdge, graph_t *graph);
void graph_delete(graph_t *graph);
size_t depth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth));
size_t dfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
	size_t depth);
size_t max(size_t a, size_t b);
size_t breadth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth));
int queue_pop(queue_t *queue, vertex_t **vertex, size_t *depth);
int queue_push(queue_t *queue, vertex_t *vertex, size_t depth);
void queue_free(queue_t *queue);

#endif /* _GRAPHS_H_ */
