#include "sort.h"


/**
 * hoare_part - hoare partitioning scheme method
 * @array: the specified array to sort
 * @size: size of array
 * @left: left start of the array or subarray
 * @right: right end of the array or subarray
 * Return: the index of pivot point
 */

int hoare_part(int *array, size_t size, int left, int right)
{
    int pv = array[right];
    int i = left - 1;
    int j = right + 1;
    int tmp;

	while (1)
	{
		do
			i++;
		while (array[i] < pv);
		do
			j--;
		while (array[j] > pv);
		if (i >= j)
			return(i);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * recursive_quick - sorts array in quick recursive method
 * @array: array to sort
 * @size: size of the array
 * @left: left start of the array or subarray
 * @right: right end of the array or subarray
 */

void recursive_quick(int *array, size_t size, int left, int right)
{
	int pvt;

	if (left >= right || left < 0)
		return;
	pvt = hoare_part(array, size, left, right);
	recursive_quick(array, size, left, pvt - 1);
	recursive_quick(array, size, pvt, right);

}

/**
 * quick_sort_hoare - sorts array of size n in quick sort way
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;
	if (!array)
		return;
	recursive_quick(array, size, 0, size - 1);
}
