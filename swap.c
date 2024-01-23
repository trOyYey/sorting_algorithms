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
