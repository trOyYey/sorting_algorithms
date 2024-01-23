#include "sort.h"

/**
 * heap_sort - fxn sorts an arr using the sift-down algorithm heap sort
 * @array: the given array
 * @size: the sizemofmthe array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)                                                          return;

	/* to heapify (max) the array; i is last non leaf node */
	for (i = size / 2 - 1; (int)i >= 0; i--) /* iteration goes back to root */
		sift_down(array, size, i);

	/* to extract largest (array[0]) and order them from rear of array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);

		sift_down(array, i, 0);
	}
}

/**
 * sift_down - sorts a distorted node down to its leaf unto max
 * @array: the given array/heap
 * @size: the size of the array
 * @i: the distorted node
 */
void sift_down(int *array, size_t size, size_t i)
{
	size_t L, R, largest;

	if (array == NULL || size < 2)
		return;
	largest = i; /* also the distorted node */
	L = 2 * i + 1; /* index of left node of i */
	R = 2 * i + 2; /* index of right node of i */

	if (size > L && array[L] > array[largest])
		largest = L;
	if (size > R && array[R] > array[largest])
		largest = R;
	if (largest != i)
	{
		swap(&array[largest], &array[i]);
		sift_down(array, size, largest);
	}
}
