#include "heap.h"

/**
 * binary_tree_node - creates a generic Binary Tree node
 *
 * @parent: a pointer to the parent node of the node to be created
 * @data: the data to be stored in the node
 * Return: binary_tree_node_t*
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new = malloc(sizeof(binary_tree_node_t));

	if (!new)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}
