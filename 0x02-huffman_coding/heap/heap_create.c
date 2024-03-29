#include "heap.h"

/**
 * heap_create - creates a Heap data structure
 *
 * @data_cmp: a pointer to a comparison function
 * Return: heap_t*
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap = malloc(sizeof(heap_t));

	if (new_heap == NULL)
		return (NULL);

	new_heap->data_cmp = data_cmp;
	new_heap->root = NULL;
	new_heap->size = 0;
	return (new_heap);
}
