#include "rb_trees.h"


/**
 * array_to_rb_tree - Create a red-black tree from a given array of integers
 * @array: The array of integers to create a red-black tree from
 * @size: The quantity of items in the array
 * Return: The address of the root node of the red-black tree
*/
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *tree;
	size_t outer = 0, inner = 0;

	if (array == NULL)
		return (NULL);

	for (outer = 0; outer < size; outer++)
	{
		for (inner = 0; inner < size && inner != outer; inner++)
		{
			if (array[outer] == array[inner])
				goto SKIP;
		}
		rb_tree_insert(&tree, array[outer]);
SKIP:
	;
	}

	return (tree);
}
