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
 * rb_delete_fix_left - Perform the fix for the left half of moved node's
 * subtree when a node is deleted
 * @root: The address of the pointer of the root of the moved node's red-black tree
 * @fix_node: The moved node of the red-black tree after node deletion
 * Return: The root node
*/

rb_tree_t *rb_delete_fix_left(rb_tree_t **root, rb_tree_t *fix_node)
{
	rb_tree_t *red_node = fix_node->parent->left;

	if (red_node && red_node->color == RED)
	{
		red_node->color = BLACK;
		fix_node->parent->color = RED;
		rb_tree_rotate_right(root, fix_node->parent);
		red_node = fix_node->parent->left;
	}
	if (red_node && red_node->right->color == BLACK &&
		red_node->left->color == BLACK)
	{
		red_node->color = RED;
		fix_node = fix_node->parent;
	}
	else if (red_node && red_node->left->color == BLACK)
	{
		red_node->color = RED;
		red_node->right->color = BLACK;
		rb_tree_rotate_left(root, red_node);
		red_node = fix_node->parent->left;
	}
	red_node->color = fix_node->parent->color;
	fix_node->parent->color = BLACK;
	red_node->right->color = BLACK;
	rb_tree_rotate_right(root, fix_node->parent);

	return (*root);
}

/**
 * rb_delete_fix_right - Perform the fix for the right half of moved node's
 * subtree when a node is deleted
 * @root: The address of the pointer of the root of the moved node's red-black tree
 * @fix_node: The moved node of the red-black tree after node deletion
 * Return: The root node
*/

rb_tree_t *rb_delete_fix_right(rb_tree_t **root, rb_tree_t *fix_node)
{
	rb_tree_t *red_node = fix_node->parent->right;

	if (red_node && red_node->color == RED)
	{
		red_node->color = BLACK;
		fix_node->parent->color = RED;
		rb_rotate_left(root, fix_node->parent);
		red_node = fix_node->parent->right;
	}
	if (red_node && red_node->left->color == BLACK &&
		red_node->right->color == BLACK)
	{
		red_node->color = RED;
		fix_node = fix_node->parent;
	}
	else if (red_node && red_node->right->color == BLACK)
	{
		red_node->left->color = BLACK;
		red_node->color = RED;
		rb_rotate_right(root, red_node);
		red_node = fix_node->parent->right;
	}
	red_node->color = fix_node->parent->color;
	fix_node->parent->color = BLACK;
	red_node->right->color = BLACK;
	rb_rotate_left(root, fix_node->parent);

	return (*root);
}


/**
 * rb_tree_remove_fix - Fix the displaced node and its subtree when a node is
 * going to be deleted
 * @root: The address of the root of the red-black tree
 * @fix_node: The address of the node that needs to be fixed
 * Return: The root of the red-black tree after the fixes are done
*/
rb_tree_t *rb_tree_remove_fix(rb_tree_t *root, rb_tree_t *fix_node)
{
	if (!root || !fix_node)
		return (root);

	while (fix_node != NULL && fix_node->color == BLACK)
	{
		if (fix_node == fix_node->parent->left)
			fix_node = rb_delete_fix_right(&root, fix_node);
		else
			fix_node = rb_delete_fix_left(&root, fix_node);
	}
	if (fix_node)
		fix_node->color = BLACK;

	return (root);
}


/**
 * rb_reattach - Fills in the vacuum that will be created when the node to
 * delete is removed by moving the fix_node into the deleted node's place
 * @root: The address of root of the red-black tree that the removal happened in
 * @del_node: The address of the node that is being deleted
 * @fix_node: The address of the node that needs to be fixed by moving it into
 * del_node's place.
 * Return: void
*/

void rb_reattach(rb_tree_t **root, rb_tree_t *del_node, rb_tree_t *fix_node)
{
	if (del_node->parent == NULL)
		*root = fix_node;
	else if (del_node->parent->left && del_node == del_node->parent->left)
		del_node->parent->left = fix_node;
	else
		del_node->parent->right = fix_node;
	if (fix_node)
		fix_node->parent = del_node->parent;
}

/**
 * tree_min_node - Find the node with the lowest value in the red-black tree
 * @root: The root node of the red-black tree
 * Return: The address of the node with the lowest value in the red-black tree
*/
rb_tree_t *tree_min_node(rb_tree_t *root)
{
	rb_tree_t *min_node = root;

	while (min_node->left)
		min_node = min_node->left;

	return (min_node);
}

/**
 * rb_tree_remover - Deletes a particular node from a given red-black tree
 * @root: The address of root of the red-black tree to remove the node from
 * @del_node: The address of the node to delete from the red-black tree
 * Return: The address of the root node of the red-black tree after deletion
*/

rb_tree_t *rb_tree_remover(rb_tree_t *root, rb_tree_t *del_node)
{
	rb_tree_t *fix_node = NULL, *min_node = NULL;
	rb_color_t old_color = del_node->color;

	if (!del_node || !root)
		return (root);

	if (!del_node->left)
	{
		fix_node = del_node->right;
		rb_reattach(&root, del_node, fix_node);
	}
	else if (!del_node->right)
	{
		fix_node = del_node->left;
		rb_reattach(&root, del_node, fix_node);
	}
	else
	{
		min_node = tree_min_node(del_node->right);
		if (min_node->color)
			old_color = min_node->color;
		fix_node = min_node->right;
		if (min_node->parent && min_node->parent == del_node)
			fix_node->parent = min_node;
		else
		{
			rb_reattach(&root, min_node, min_node->right);
			min_node->right = del_node->right;
			min_node->right->parent = min_node;
		}
		rb_reattach(&root, del_node, min_node);
		min_node->left = del_node->left;
		min_node->left->parent = min_node;
		min_node->color = del_node->color;
	}
	if (old_color == BLACK)
		rb_delete_fix(root, fix_node);
	free(del_node);
	return (root);
}

/**
 * rb_tree_remove - Entry point to delete a node from a red-black tree,
 * finds the node in the tree and calls rb_tree_remover to delete the node
 * @root: The root node of the red-black tree
 * @n: The value to delete from the red-black tree
 * Return: The root node of the modified red-black tree
*/
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *del_node = root;

	if (!del_node)
		return (NULL);

	while (del_node && del_node->n != n)
	{
		if (!del_node->left && !del_node->right)
			return (root);
		if (del_node->n < n)
			del_node = del_node->right;
		else
			del_node = del_node->left;
	}

	return (rb_tree_remover(root, del_node));
}
