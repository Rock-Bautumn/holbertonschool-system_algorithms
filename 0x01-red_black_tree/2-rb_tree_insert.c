#include "rb_trees.h"

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

/**
 * rb_fix_insert - Fixes the red-black tree configuration after the node has
 * been added
 * @tree: The root of the red-black tree
 * @new_node: The node just added to the red-black tree
 * Return: void
*/

void rb_fix_insert(rb_tree_t **tree, rb_tree_t *new_node)
{
	while (new_node->parent && new_node->parent->color == RED)
	{
		if (new_node->parent->parent &&
		new_node->parent == new_node->parent->parent->left)
			new_node = rb_fix_right(tree, new_node);
		else
			new_node = rb_fix_left(tree, new_node);
	}
	(*tree)->color = BLACK;
}

/**
 * rb_fix_left - Fix the right child of a red-black tree node after insertion
 * @tree: The red-black tree root
 * @new_node: The node added to the red-black tree
 * Return: The new node
*/

rb_tree_t *rb_fix_left(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *gP = new_node->parent->parent, *uncle = gP->left;

	if (uncle && uncle->color == RED)
	{
		new_node->parent->color = BLACK;
		uncle->color = BLACK;
		gP->color = RED;
		new_node = gP;
	}
	else
	{
		if (new_node == new_node->parent->left)
		{
			new_node = new_node->parent;
			rb_tree_rotate_right(tree, new_node);
		}
		new_node->parent->color = BLACK;
		gP->color = RED;
		rb_tree_rotate_left(tree, gP);
	}
	return (new_node);
}

/**
 * rb_fix_right - Fix the right child of a red-black tree node after insertion
 * @tree: The red-black tree root
 * @new_node: The node added to the red-black tree
 * Return: The new node
*/

rb_tree_t *rb_fix_right(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *gP = new_node->parent->parent, *uncle = gP->right;

	if (uncle && uncle->color == RED)
	{
		new_node->parent->color = BLACK;
		uncle->color = BLACK;
		gP->color = RED;
		new_node = gP;
	}
	else
	{
		if (new_node == new_node->parent->right)
		{
			new_node = new_node->parent;
			rb_tree_rotate_left(tree, new_node);
		}
		new_node->parent->color = BLACK;
		gP->color = RED;
		rb_tree_rotate_right(tree, gP);
	}
	return (new_node);
}

/**
 * rb_tree_insert - Insert a node into a red-black tree
 * @tree: The red-black tree root
 * @value: The value to store inside the tree
 * Return: The address of the newly created node that was inserted
*/

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node = NULL, *old_node = NULL, *new_node = NULL;

	if (!tree)
		return (NULL);

	node = *tree;

	while (node != NULL)
	{
		old_node = node;
		if (node->n == value)
			return (NULL);
		else if (node->n > value)
			node = node->left;
		else
			node = node->right;
	}

	new_node = rb_tree_node(old_node, value, RED);

	if (!new_node)
		return (NULL);
	if (old_node == NULL)
		*tree = new_node;
	else if (new_node->n < old_node->n)
		old_node->left = new_node;
	else
		old_node->right = new_node;

	rb_fix_insert(tree, new_node);

	return (new_node);
}
