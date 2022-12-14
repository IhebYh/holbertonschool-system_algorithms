#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);

int rb_tree_is_valid(const rb_tree_t *tree);
int tree_validity(const rb_tree_t *tree);

void rb_tree_print(const rb_tree_t *tree);

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
void left_leaf(rb_tree_t **tree, rb_tree_t *node);
void right_leaf(rb_tree_t **tree, rb_tree_t *node);
void fix_insertion(rb_tree_t **tree, rb_tree_t *node);
void right_rotate(rb_tree_t **tree, rb_tree_t *node);
void left_rotate(rb_tree_t **tree, rb_tree_t *node);

rb_tree_t *array_to_rb_tree(int *array, size_t size);

#endif /* _RB_TREES_H_ */
