#include "rb_trees.h"


/**
 * array_to_rb_tree - builds a BST from an array
 *
 * @array : array
 * @size : size of the array
 * Return: rb_tree_t
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	int *array_len;
	rb_tree_t *tree = NULL;

	for (array_len = array + size; array < array_len; array++)
		rb_tree_insert(&tree, *array);

	return (tree);
}
