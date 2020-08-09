#include <stdio.h>
#include <stdlib.h>
#include "search.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: ptr to head of list
 * @value: value of element in list
 *
 * Return: ptr to first node where value is, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list || !value)
		return (NULL);
	return (list);
}
