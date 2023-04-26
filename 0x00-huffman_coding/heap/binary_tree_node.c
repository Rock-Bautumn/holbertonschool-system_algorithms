#include "heap.h"

/**
 * binary_tree_node - Create a generic binary tree node
 * @parent: The parent node of the newly created node
 * @data: The address of the data to store in the node
 * Return: The address of the newly created node
*/
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node = malloc(sizeof(binary_tree_node_t));

	if (!new_node)
		return (NULL);

	new_node->data = data;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
