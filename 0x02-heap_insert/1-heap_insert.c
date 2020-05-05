#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heapt_t *heap_insert -inserts value into Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to put in the inserted node
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{

	binary_tree_t *newroot;

	if (!root)
		return (NULL);
	newroot = binary_tree_node(NULL, value);

	if (!*root)
	{
		*root = newroot;
		return (newroot);
	}
	return (NULL);
}
