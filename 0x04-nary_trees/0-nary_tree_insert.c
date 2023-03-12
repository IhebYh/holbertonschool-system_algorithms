#include "nary_trees.h"

/**
 * nary_tree_insert - inserts a node in a N-ary tree
 * @parent: a pointer to the parent node
 * @str: string to be stored in the created node
 * Return: nary_tree_t*
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new;

	new = malloc(sizeof(nary_tree_t));
	if (!new)
		return (NULL);
	new->content = strdup(str);
	new->parent = parent;
	new->nb_children = 0;
	new->children = NULL;
	new->next = NULL;

	if (new && parent)
	{
		parent->nb_children++;
		if (parent->children)
			new->next = parent->children;
		parent->children = new;
	}

	return (new);
}
