#include "sort.h"

/**
 * counting_sort - fxn sorts an array using counting sort algorithm
 * @array: the given array
 * @size: the aray size
 */
void counting_sort(int *array, size_t size)
{
	size_t max, i, index = 0;
	int *freq_array;

	if (array == NULL || size < 2)
		return;

	/* find the maximum value in array */
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	/**
	 * create a frequency array containing number of
	 * times an element occure in the array
	 */
	freq_array = malloc(sizeof(int) * (max + 1));
	if (freq_array == NULL)
		return;
	/* initialize freq_array to 0 */
	for (i = 0; i < max + 1; i++)
		freq_array[i] = 0;
	/* count and store frequency value */
	for (i = 0; i < size; i++)
		freq_array[array[i]]++;
	/* print the counting array */
	print_array(freq_array, max + 1);
	/* copy sorted elements to org. array */
	for (i = 0; i < max + 1; i++)
	{	/* this condition ensures on existing values are discarded */
		while (freq_array[i] > 0)
		{
			array[index] = i;
			index++;
			freq_array[i]--;
		}
	}
	free(freq_array);
}
