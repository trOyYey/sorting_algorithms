#include "sort.h"
#define parentheap(x) (((x) - 1) / 2)
#define leftchildheap(x) (((x) * 2) + 1)

/**
 * swap - swap between two variables
 * @var1: the first variable
 * @var2: the second variable
 */

void swap_plus_print(int *array, size_t size, int *var1, int *var2)
{
	if (*var1 != *var2)
	{
		*var1 = *var1 + *var2;
		*var2 = *var1 - *var2;
		*var1 = *var1 - *var2;
	}
	print_array((const int *) array, size);
}

/**
 * heap_struct - heapify function
 * @array: array to heapify
 * @size: size of the array
 */

void heap_struct(int *array, size_t size)
{
	ssize_t left;
	
	for (left = parentheap(size - 1); left >= 0; left--)
	{
		sift_down(array, left, size - 1, size);
	}
}

/**
 * heap_sort - fxn sorts an arr using the sift-down algorithm heap sort
 * @array: the given array
 * @size: the sizemofmthe array
 */

void heap_sort(int *array, size_t size)
{
	size_t right;

	if (array == NULL || size < 2)
		return;

	heap_struct(array, size);
	for (right = size - 1; right > 0;)
	{
		swap_plus_print(array, size, &array[right], &array[0]);
		right--;
		sift_down(array, 0, right, size);
	}
}

/**
 * sift_down - sorts a distorted node down to its leaf unto max
 * @array: the given array/heap
 * @size: the size of the array
 * @i: the distorted node
 */

void sift_down(int *array, size_t left, size_t right, size_t size)
{
	size_t seed, _switch, child;

	for (seed = left; leftchildheap(seed) <= right; seed = _switch)
	{
		child = leftchildheap(seed);
		_switch = seed;
		if (array[_switch] < array[child])
			_switch = child;
		if (child + 1 <= right &&
				array[_switch] < array[child + 1])
			_switch = child + 1;
		if (_switch == seed )
			return;
		swap_plus_print(array, size, &array[seed], &array[_switch]);
	}
}
