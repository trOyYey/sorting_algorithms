#include "sort.h"


/**
 * merge - function that walks through merging proces for mering sort method
 * @array: original array
 * @clone: clone of the array
 * @left: left slice of the array
 * @middle: middle part of the array
 * @right: the right slice of the array
 */

void merge(int *array, size_t left, size_t middle, size_t right, int *clone)
{
	size_t i = left, j = middle, x;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&array[left], middle - left);
	printf("[right]: ");
	print_array(&array[middle], right - middle);
	x = i;
	while (x < right)
	{
		if (i < middle && (j >= right || clone[i] <= clone[j]))
		{
			array[x] = clone[i];
			i++;
		}
		else
		{
			array[x] = clone[j];
			j++;
		}
		x++;
	}
	printf("[Done]: ");
	print_array(&array[left], right - left);
}
/**
 * mergetopdown - sorting function that uses recursive method
 * @array: original array
 * @clone: copy of the array
 * @left: starting slice of the array
 * @right: ending slice of the array
 */

void mergetopdown(int *array, size_t left, size_t right, int *clone)
{
	size_t middle = (right + left) / 2;

	if (right - left <= 1)
		return;

	mergetopdown(clone, left, middle, array);
	mergetopdown(clone, middle, right, array);

	merge(array, left, middle, right, clone);
}
/**
 * merge_sort - sorting function that uses merge method
 * @array: the array that needs to be sorted
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int i, *clone;

	if (!array || size <= 1)
		return;
	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;

	for (i = 0; i < (int)size; i++)
		clone[i] = array[i];

	mergetopdown(array, 0, size, clone);
	free(clone);
	clone = NULL;
}
