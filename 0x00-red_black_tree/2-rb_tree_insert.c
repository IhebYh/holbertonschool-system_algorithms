#include "rb_trees.h"

/**
 *left_rotate - rotates subtree left
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *new = node->right;

	if (new == NULL)
		return;
	node->right = new->left;
	if (new->left)
		new->left->parent = node;
	new->left = node;
	new->parent = node->parent;
	if (node->parent == NULL)
		*tree = new;
	else if (node->parent->left == node)
		node->parent->left = new;
	else
		node->parent->right = new;

	node->parent = new;
}

/**
 * right_rotate - rotates subtree right
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *new = node->left;

	if (new == NULL)
		return;
	node->left = new->right;
	if (new->right)
		new->right->parent = node;
	new->right = node;
	new->parent = node->parent;
	if (node->parent == NULL)
		*tree = new;
	else if (node->parent->left == node)
		node->parent->left = new;
	else
		node->parent->right = new;

	node->parent = new;
}

/**
 * fix_insertion - fixes Red Black Tree after insertion
 * @tree: pointer to root node
 * @node: pointer to node inserted node
 * Return: pointer to inserted node
 */
void fix_insertion(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent && node->parent == node->parent->parent->left)
			right_leaf(tree, node);
		else
			left_leaf(tree, node);

	}
	(*tree)->color = BLACK;
}

/**
 * right_leaf -  fixes the right side
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */

void right_leaf(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->right && node->parent->parent->right->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->right->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			left_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		right_rotate(tree, node->parent->parent);
	}
}

/**
 * left_leaf -  fixes the left side
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */
void left_leaf(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->left && node->parent->parent->left->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->left->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			right_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		left_rotate(tree, node->parent->parent);
	}
}

/**
 * rb_tree_insert - inserts node into RB Tree
 * @tree: address of pointer to root node
 * @value: new value to insert
 * Return: new node on success else NULL
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node, *prev = NULL, *current;

	if (!tree)
		return (NULL);

	current = *tree;

	while (current)
	{
		prev = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	node = rb_tree_node(prev, value, RED);

	if (!node)
		return (NULL);
	if (!prev)
	{
		node->color = BLACK;
		return (*tree = node);
	}
	if (value < prev->n)
		prev->left = node;
	else
		prev->right = node;
	fix_insertion(tree, node);
	return (node);
}
