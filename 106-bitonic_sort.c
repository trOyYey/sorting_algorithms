#include "sort.h"

/**
 * dynamic_print - dynamic printing for both merging and results
 * @array: array to print
 * @lenght: len of the sub array
 * @size: size of the full array
 * @pattern: ascending or descending
 * @process: result or merging
 * @left: start of the array or sub array
 */

void dynamic_print(int *array, int left, int lenght, int size, int pattern, int process)
{
	char *var1, *var2;

	if (process)
	{
		var1 = "Result";
	}
	else
	{
		var1 = "Merging";
	}
	if (pattern)
	{
		var2 = "UP";
	}
	else
	{
		var2 = "DOWN";
	}

	printf("%s [%d/%d] (%s):\n", var1, lenght, size, var2);

	print_array(&array[left], lenght);
}
/**
 * bit_merge - merges two arrays recursively
 *
 * @array: the array to sort
 * @left: start of the array
 * @lenght: size of the array
 * @pattern: ascending or descednig
 * @size: size of the array
 */

void bit_merge(int *array, size_t left, size_t lenght, int pattern, size_t size)
{
	int pv = lenght / 2, temp;
	size_t i;

	if (lenght < 2)
		return;
	i = left;
	while (i < left + pv)
	{
		if (pattern == (array[i] > array[i + pv]))
		{
			temp = array[i], array[i] = array[i + pv];
			array[i + pv] = temp;
		}
	i++;
	}
	bit_merge(array, left, pv, pattern, size);
	bit_merge(array, left + pv, pv, pattern, size);

}

/**
 * divide_sort - sorts recursively ascending and descending
 * @array: array to sort
 * @left: index start of the array
 * @lenght: len of the array
 * @pattern: ascending or descednig
 * @size: size of the array
 *
 */

void divide_sort(int *array, size_t left, size_t lenght, int pattern, size_t size)
{
	int pv = lenght / 2;

	if (lenght < 2)
		return;
	dynamic_print(array, left, lenght, size, pattern, 0);

	divide_sort(array, left, pv, 1, size);

	divide_sort(array, left + pv, pv, 0, size);

	bit_merge(array, left, lenght, pattern, size);

	dynamic_print(array, left, lenght, size, pattern, 1);
}
/**
 * bitonic_sort - sorts linked in bitnoic sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	divide_sort(array, 0, size, 1, size);
}
