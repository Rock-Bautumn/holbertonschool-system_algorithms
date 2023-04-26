#include "nary_trees.h"

/**
 * nary_tree_traverser - Recursive helper function for the entry point function
 * nary_tree_traverse
 * @node: The current node to start traversing from (this is a recursive func)
 * @depth: The current depth of node
 * @action: A function pointer to be performed on each node
 * Return: The maximum depth encountered during traversal
 */

size_t nary_tree_traverser(nary_tree_t const *node, size_t depth,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t child_depth, max_depth;
	nary_tree_t const *child;

	if (!node)
		return (depth);

	action(node, depth);

	max_depth = depth;

	for (child = node->children; child; child = child->next)
	{
		child_depth = nary_tree_traverser(child, depth + 1, action);
		if (child_depth > max_depth)
			max_depth = child_depth;
	}

	return (max_depth);
}

/**
 * nary_tree_traverse - Go through an N-ary tree node-by-node and perform an
 * action on each node. This function is the entry point for the recursive
 * helper function nary_tree_traverser.
 * @root: The address of the root/starting point to traverse from.
 * @action: A function pointer for the function that will be performed on each
 * node.
 * Return: The maximum depth found in the N-ary tree
*/
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	return (nary_tree_traverser(root, 0, action));
}
