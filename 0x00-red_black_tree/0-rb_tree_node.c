#include "rb_trees.h"

/**
 * rb_tree_node - creates a Red-Black Tree node
 * @parent : pointer to the parent node
 * @value : the value stored
 * @color : black or red
 * Return: rb_tree_t*
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{

	rb_tree_t *new_node;

	new_node = malloc(sizeof(rb_tree_t));
	if (new_node)
	{
		new_node->parent = parent;
		new_node->n = value;
		new_node->color = color;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
	}
	return (NULL);
}
