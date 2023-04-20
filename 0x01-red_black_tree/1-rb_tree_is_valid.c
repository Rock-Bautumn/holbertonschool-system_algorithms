#include "rb_trees.h"

/**
 * valid_colors - Check if the child colors are valid for the tree
 * @tree: The tree to check the colors of
 * Return: 1/true if true, 0/false if false
*/

bool valid_colors(rb_tree_t *tree)
{
	if (tree == NULL)
		return (true);

	if (tree->color != BLACK && tree->color != RED)
		return (false);

	if (tree->color == RED)
	{
		if (tree->left && (tree->left)->color == RED)
			return (false);
		if (tree->right && (tree->right)->color == RED)
			return (false);
	}

	return (valid_colors(tree->left) && valid_colors(tree->right));
}

/**
 * is_valid_bst - Check to see if a node is a valid binary search tree
 * @node: binary tree to check
 * @min: The minimum number encountered in the left subtree
 * @max: The maximum number encountered in the right subtree
 * Return: true/1 if valid BST, false/0 if not valid BST
*/

bool is_valid_bst(rb_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (true);

	if ((min && node->n < min) || (max && node->n > max))
		return (false);

	return (is_valid_bst(node->left, min, node->n) &&
		is_valid_bst(node->right, node->n, max));
}

/**
 * black_height - Find the black height of the node
 * @node: The node to find the height of
 * Return: The height of the node
*/

size_t black_height(rb_tree_t *node)
{
	size_t height;

	if (node == NULL)
		return (false);

	height = MAX(black_height(node->left), black_height(node->right));

	if (node->color == BLACK)
		height++;

	return (height);
}

/**
 * check_rb_height - Check the red-black height of the tree
 * @node: The tree node to start checking from
 * @black_height: The black height to compare against
 * @rb_height: The red-black height to compare against
 * Return: The red-black height of the tree node
*/

size_t check_rb_height(rb_tree_t *node, size_t black_height, size_t rb_height)
{
	if (node == NULL)
	{
		if (rb_height == black_height)
			return (true);
		return (false);
	}
	if (node->color == BLACK)
		rb_height++;

	return (check_rb_height(node->left, black_height, rb_height) &&
		check_rb_height(node->right, black_height, rb_height));
}

/**
 * rb_tree_is_valid - Check if a red-black tree is a valid/properly configured
 * red-black tree
 * @tree: The tree node to check from
 * Return: 1/true if it is valid, 0/false if it is invalid
*/

int rb_tree_is_valid(rb_tree_t *tree)
{
	size_t blk_height;

	if (tree == NULL)
		return (false);

	if (tree->color != BLACK)
		return (false);

	if (valid_colors(tree) == false)
		return (false);

	if (is_valid_bst(tree, 0, 0) == false)
		return (false);

	blk_height = black_height(tree);

	if (check_rb_height(tree, blk_height, 0) == false)
		return (false);

	return (true);
}
