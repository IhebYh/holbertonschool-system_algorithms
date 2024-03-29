#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include "queues.h"
#include "graphs.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;


queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
int backtrack(char **map, int rows, int cols, point_t const *start,
	point_t const *target, int x, int y, queue_t *path);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
int dfs(vertex_t const *vertex);

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);

queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);

#endif /* _PATHFINDING_H_ */
