#include "nary_trees.h"

/**
 * nary_tree_delete - Delete an N-ary tree and all of its children (recursive)
 * @tree: The address of the tree to free its children, grandchildren,
 * etc to delete (free)
 * Return: void
*/

void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *free_tree;

	if (!tree)
		return;

	while (tree)
	{
		free_tree = tree;
		tree = tree->next;
		nary_tree_delete(free_tree->children);
		free(free_tree->content);
		free(free_tree);
	}
}
