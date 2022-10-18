#include "rb_trees.h"

/**
 * tree_validity - recursively valildates RB tree properties
 * @tree: pointer to root of tree to validate
 * Return: 1 if valid else 0
 */
int tree_validity(const rb_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (!tree->color)
		return (0);

	if (tree->color == RED)
	{
		if (tree->parent->color == tree->color)
			return (0);
		if (tree->color == tree->left->color || tree->color == tree->right->color)
			return (0);
	}

	if (tree->left && !tree->right)
		return (0);
	if (!tree->left && tree->right)
		return (0);

	return (tree_validity(tree->right) && tree_validity(tree->left));
}
/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-balck tree
 * @tree : a pointer to the root node
 * Return: int
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree || tree->color != BLACK)
		return (0);
	return (tree_validity(tree->right) && tree_validity(tree->left));
}
