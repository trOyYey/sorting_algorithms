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
 * lomuto - lomuto partition method.
 * @arr: the array
 * @size: size of array
 * @low: lowest starting point of the array
 * @high: highest ending of the array
 * Return: the index of pivot point
 */

int lomuto(int arr[], size_t size, int low, int high)
{
	int pivot = arr[high];
	int pivotid = low;
	int currentid;

	for (currentid = low; currentid < high; currentid++)
	{
		if (arr[currentid] <= pivot)
		{
			swap(&arr[pivotid], &arr[currentid]);
			pivotid++;
			if (arr[pivotid - 1] != arr[currentid])
			{
				print_array(arr, size);
			}
		}
	}

	swap(&arr[pivotid], &arr[high]);
	if (arr[pivotid] != arr[high])
	{
		print_array(arr, size);
	}
	return (pivotid);
}

/**
 * quick_recursive - sorts array using quck sorting recursive
 * @array: the array
 * @size: size of array
 * @low: lowest starting point of the array
 * @high: highest ending of the array
 *
 */

void quick_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low >= high || high < 0)
		return;
	pivot = lomuto(array, size, low, high);
	quick_recursive(array, size, low, pivot - 1);
	quick_recursive(array, size, pivot + 1, high);
}

/**
 * quick_sort - sorts array of size n in quick sort way
 *
 * @arr: array to sort
 * @size: size of the array
 */

void quick_sort(int *arr, size_t size)
{
	if (!arr || size <= 1)
		return;
	quick_recursive(arr, size, 0, size - 1);
}
