#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts array based on significant digit
 * @array: ptr to array
 * @size: size of array
 * @exp: current exponent
 */
void counting_sort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output = malloc(sizeof(int) * size);
	int i;

	for (i = 0; i < (int)size ; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - sorts array of ints in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, i;

	if (size < 2 || !array)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
