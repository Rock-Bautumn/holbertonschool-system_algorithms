#include "nary_trees.h"

/**
 * nary_tree_insert - Insert a node into an N-ary tree
 * @parent:The address of the parent node
 * @str: The string to be stored in the node as a copy
 * Return: The address of the created node, or NULL if failure
 */

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node = malloc(sizeof(nary_tree_t));
	char *new_string = strdup(str);

	if (!new_node)
		return (NULL);

	if (!new_string)
	{
		free(new_node);
		return (NULL);
	}

	new_node->children = NULL;
	new_node->content = new_string;
	new_node->nb_children = 0;
	new_node->next = NULL;
	new_node->parent = parent;

	if (parent)
	{
		new_node->next = parent->children;
		parent->children = new_node;
		parent->nb_children++;
	}

	return (new_node);
}
