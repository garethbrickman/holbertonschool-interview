#include "sort.h"

/**
 * merge_sort - sort an array merging sorted sub arrays
 * @array: the array to merge_sort
 * @size: the length of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buff = NULL;

	if (array == NULL || size == 0)
		return;
	buff = malloc(size * sizeof(int));
	if (buff == NULL)
		return;
}
