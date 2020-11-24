#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts array of ints in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
	{
		print_array(array, size);
	}
}
