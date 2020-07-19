#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * count_nodes - counts the number of nodes inside the tree.
 * @tree: binary tree node.
 * Return: number of nodes in the tree.
 */
int count_nodes(heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - function that checks if tree is complete.
 * @tree: binary tree node.
 * @index: index of the tree.
 * @n: number of nodes.
 * Return: 1 on success 0 on failure.
 */
heap_t *is_complete(heap_t *tree, int index, int n)
{
	heap_t *left, *right;

	if ((tree->left) && !(tree->right))
		return (tree);
	if (!(tree->left) && !(tree->right))
	{
		if (index == n)
			return (NULL);
		else
			return (tree);
	}

	left = is_complete(tree->left, (2 * index) + 1, n);
	right = is_complete(tree->right, (2 * index) + 2, n);

	if  (left)
		return (left);
	else
		return (right);
}

/**
 * heapt_t *heap_insert -inserts value into Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to put in the inserted node
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;
	int size;

	new = malloc(sizeof(heap_t));

	if (!new)
		return (NULL);
	parent = malloc(sizeof(heap_t));
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	if (!*root)
	{
		*root = new;
		return (new);
	}

	size = count_nodes(*root);
	parent = is_complete(*root, 0, size);
	if (!parent->left)
	{
		parent->left = new;
		new->parent = parent;
	}
	else
	{
		parent->right = new;
		new->parent = parent;
	}
	return (new);
}
