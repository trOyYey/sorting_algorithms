#include "sort.h"

/**
 * swap - swap between two variables
 * @var1: the first variable
 * @var2: the second variable
 */

void swap(int *var1, int *var2)
{
	int temp;

	temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

/**
 * selection_sort - sorts an array using the selection algorithm
 * @array: the given array ti be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
