#ifndef _HEAP_H_
#define _HEAP_H_


#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void swap_node_with_parent(binary_tree_node_t *node);
void *heap_extract(heap_t *heap);
void heapify(binary_tree_node_t *node, heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));
void tree_delete(binary_tree_node_t *tree, void (*free_data)(void *));


#endif /* _HEAP_H_ */