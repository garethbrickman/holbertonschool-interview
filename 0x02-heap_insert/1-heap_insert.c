#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * find_insert_node - finds the node to insert the child in
 * @root: the root of the tree
 * @height: the current node height
 * @maxheight: the max tree height
 * Return: the node to enter the child in
 */
binary_tree_t *find_insert_node(binary_tree_t *root, int height, int maxheight)
{
	binary_tree_t *x;
	binary_tree_t *y;

	if ((root->left) && !(root->right))
		return (root);
	if (!(root->left || root->right))
	{
		if (height == maxheight)
			return (NULL);
		else
			return (root);
	}

	x = find_insert_node(root->left, height + 1, maxheight);
	y = find_insert_node(root->right, height + 1, maxheight);
	if (x)
		return (x);
	else
		return (y);
}


/**
 * change_attributes - swaps all three attributes on two nodes.
 * @node1: the first node
 * @node2: the second node
 */
void change_attributes(binary_tree_t *node1, binary_tree_t *node2)
{
	binary_tree_t *temp;

	temp = node2->parent;
	node2->parent = node1->parent;
	node1->parent = temp;

	temp = node2->left;
	node2->left = node1->left;
	node1->left = temp;

	temp = node2->right;
	node2->right = node1->right;
	node1->right = temp;
}


/**
 * change - change an item with its parent
 * @item: the item
 * @parent: the parent
 */
void change(binary_tree_t *item, binary_tree_t *parent)
{
	change_attributes(item, parent);
	parent->parent = item;
	if (item->left == item)
	{
		item->left = parent;
		if (item->right)
			item->right->parent = item;
	}
	if (item->right == item)
	{
		item->right = parent;
		if (item->left)
			item->left->parent = item;
	}

	if (item->parent)
	{
		if (item->parent->left == parent)
			item->parent->left = item;
		if (item->parent->right == parent)
			item->parent->right = item;
	}

	if (parent->left)
		if (parent->left->parent == item)
			parent->left->parent = parent;

	if (parent->right)
		if (parent->right->parent == item)
			parent->right->parent = parent;
}



/**
 * max_heapify - turn heap into heap
 * @x: the current bubble-up node
 * Return: the root of the heapified tree
 */
heap_t *max_heapify(binary_tree_t *x)
{
	binary_tree_t *y;

	y = x;
	while (y->parent && y->n > y->parent->n)
		change(y, y->parent);
	while (y->parent)
		y = y->parent;
	return ((heap_t *)y);
}

/**
 * heapt_t *heap_insert -inserts value into Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to put in the inserted node
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *x;
	binary_tree_t *to_insert;
	binary_tree_t *temp;
	int h = 0;

	if (!root)
		return (NULL);
	x = binary_tree_node(NULL, value);
	if (x == NULL)
		return (NULL);
	if (!(*root))
	{
		*root = x;
		return (x);
	}
	temp = *root;
	while (temp->left)
	{
		temp = temp->left;
		h = h + 1;
	}
	to_insert = find_insert_node(*root, 0, h);
	if (!to_insert)
	{
		to_insert = *root;
		while (to_insert->left)
			to_insert = to_insert->left;
	}
	if (to_insert->left)
		to_insert->right = x;
	else
		to_insert->left = x;
	x->parent = to_insert;
	*root = max_heapify(x);
	return (x);
}
