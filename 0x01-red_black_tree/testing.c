#include <stdio.h>
#include <stdlib.h>

void check_dup(int *array, size_t size)
{
	size_t outer = 0, inner = 0;

	for (outer = 0; outer < size; outer++)
	{
		for (inner = 0; inner < size && inner != outer; inner++)
		{
			if (array[outer] == array[inner])
				goto SKIP;
		}
		printf("added %d\n", array[outer]);
SKIP:
	;
	}
}

int main(void)
{
	int array[] = {6, 3, 2, 1, 7, 2, 9, 2, 4, 2, 8, 5};
	size_t size = 12;

	check_dup(array, size);
	return (0);
}
