#include "rb_trees.h"

/**
 * rb_tree_node - Creates a new node of a red-black tree
 * @parent: The parent node of the newly created node
 * @value: The n value saved in the new node
 * @color: The color to associate with the new node
 * Return: The newly created red-black tree node
*/

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node;

	if (color > DOUBLE_BLACK || color < RED)
		return (NULL);

	new_node = malloc(sizeof(rb_tree_t));
		if (new_node == NULL)
			return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->color = color;

	return (new_node);
}
