#include "sort.h"

/**
 * get_digit - gets dgit
 *
 * @number: number
 * @position: place of digit
 * Return: specified digit
 */

int get_digit(int number, int position)
{
	for (; position > 1; position--)
	{
	number /= 10;
	}
	return (number % 10);
}

/**
 * get_ldigits - finds biggest amount of digits in biggest number
 * @array: the array to sort
 * @size: size of array
 * Return: the lenght of the digits needed
 */
int get_ldigits(int *array, size_t size)
{
	int n;
	int num_digits = 0;

	if (size == 0)
		return (0);

	n = array[size - 1];
	while (size-- > 0)
	{
		if (n < array[size])
			n = array[size];
	}
	while (n != 0)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

/**
 * radix_sort - function that uses radix LSD method
 * @array: the array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max_digits, *clone, *count, i, j;

	if (!array || size <= 1)
		return;
	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(clone);
		return;
	}
	max_digits = get_ldigits(array, size);
	i = 1;
	while (i < max_digits + 1)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < (int) size; j++)
			count[get_digit(array[j], i)]++;
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = size - 1; j >= 0; j--)
			clone[count[get_digit(array[j], i)]-- - 1] = array[j];
		for (j = 0; j < (int) size; j++)
		array[j] = clone[j];
		print_array(array, size);
		i++;
	}
	free(clone);
	free(count);
}
