#include "sort.h"

/**
 * bubble_sort - fxn sort an array using burble sort algorithm
 * and print array after each swap
 * @array: the given array to be sorted
 * @size: the size of the array
 *
 * description: note, this is an optimized version for 2 reasons:
 * ONE -> in some cases, sorting is complete after 1 or 2 iterations,
 * so we use swapped flag. if no swap was done we break iteration.
 * TWO -> iteration need not be repeated on sorted elements, so we
 * minus i from (j < n - 1) in second iteration
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!(swapped))
			break;
	}
}
