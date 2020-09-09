#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void maxHeapify(int *array, int size, int i, int orig_size);
void swap(int *array1, int *array2);

#endif /* _SORT_H_ */
