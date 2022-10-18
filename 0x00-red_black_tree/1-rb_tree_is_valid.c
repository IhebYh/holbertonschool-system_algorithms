#include "rb_trees.h"

/**
 * computeBlackHeight - compute theblack height
 * @currNode : current node
 * Return: int
 */

int computeBlackHeight(const rb_tree_t *currNode) 
{
    if (currNode == NULL)
        return 0; 

    int leftHeight = computeBlackHeight(currNode->left);
    int rightHeight = computeBlackHeight(currNode->right);
    int add = currNode->color == BLACK ? 1 : 0;

    if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight)
        return -1; 
    else
        return leftHeight + add;
}
/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-balck tree
 * @tree : a pointer to the root node
 * Return: int
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	return computeBlackHeight(tree) != -1;
}
