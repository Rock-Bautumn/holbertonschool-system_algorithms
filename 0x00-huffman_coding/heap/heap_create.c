#include "heap.h"

/**
 * heap_create - Create a heap data structure
 * @data_cmp: Function pointer to a data comparison function
 * Return: The address of the created heap_t data structure, or NULL if failure
*/

heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap = malloc(sizeof(heap_t));

	if (!new_heap)
		return (NULL);

	new_heap->data_cmp = data_cmp;
	new_heap->root = NULL;
	new_heap->size = 0;

	return (new_heap);
}
