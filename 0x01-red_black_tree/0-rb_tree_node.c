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

/**
 * rb_tree_rotate_left - Rotates a red-black tree in a counter
 *  clockwise direction
 * @tree: The binary search tree to rotate
 * @node: The node to rotate around
 * Return: The newly rotated red-black tree
*/
void rb_tree_rotate_left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *root = node->right;

	node->right = root->left;

	if (root->left)
		root->left->parent = node;
	root->parent = node->parent;
	if (node->parent == NULL)
		*tree = root;
	else if (node == node->parent->left)
		node->parent->left = root;
	else
		node->parent->right = root;

	root->left = node;
	node->parent = root;
}


/**
 * rb_tree_rotate_right - Rotates a red-black tree in a clockwise direction
 * @tree: The red-black tree to rotate
 * @node: The node of the red-black tree to rotate around
 * Return: The newly rotated binary search tree
 */

void rb_tree_rotate_right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *root = node->left;

	node->left = root->right;

	if (root->right)
		root->right->parent = node;
	root->parent = node->parent;
	if (node->parent == NULL)
		*tree = root;
	else if (node == node->parent->left)
		node->parent->left = root;
	else
		node->parent->right = root;

	root->right = node;
	node->parent = root;
}
