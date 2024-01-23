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
 * shell_sort - fxn sorts an array of int using shell sort algorithm
 * @array: the given array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, k;

	/* find maximum gap value using knuth fomular */


	for (gap = 1; gap <= size / 3;  gap = gap * 3 + 1)
		;
	/* using this value and reducing it at every iteration */
	for (; gap > 0;  gap = (gap - 1) / 3)
	{
		for (i = 0; i < size; i++)
		{
			j = i + gap;
			if (j < size)
			{
				if (array[i] > array[j])
				{
					swap(&array[i], &array[j]);
					k = i - gap;
					/**
					 *  if j is right gap of i, k is left gap of i; left gap
					 *  is enforced if right gap succeeds
					 */
					if ((int)k >= 0 && (array[k] > array[i]))
						swap(&array[k], &array[i]);
				}
			}
			else
			{
			/* to ensure ith loop does not continue if jth >=size */
				i = size;
				break;
			}
		}
		print_array(array, size);
	}
}
