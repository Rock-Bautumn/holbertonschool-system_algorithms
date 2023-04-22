#include "rb_trees.h"

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
	}

	return (tree);
}
