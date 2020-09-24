#include "binary_trees.h"

/**
 * move_node - moves node down tree
 * @node: node to move down
 */
void move_node(heap_t *node)
{
	heap_t *largest = NULL;
	int temp;

	if (node->right)
	{
		if (node->right->n > node->left->n)
			largest = node->right;
		else
			largest = node->left;
	}
	else if (node->left)
		largest = node->left;

	if (largest && largest->n > node->n)
	{
		temp = largest->n;
		largest->n = node->n;
		node->n = temp;
		move_node(largest);
	}
}
/**
 * get_height - finds the max depth of the tree
 * @node: root node of tree
 * Return: depth of tree
 * A
 */
int get_height(heap_t *node)
{
	int l, r;

	if (!node)
		return (0);

	l = get_height(node->left);
	r = get_height(node->right);

	if (l > r)
		return (l + 1);
	return (r + 1);
}
/**
 * get_last_node - gets the last most right node of the tree
 * @height: depth of the tree
 * @rec_height: counter for recursive height value
 * @node: node
 * Return: last node
 */
heap_t *get_last_node(int height, int rec_height, heap_t *node)
{
	heap_t *left;
	heap_t *right;

	if (rec_height != height)
	{
		left = get_last_node(height, rec_height + 1, node->left);
		right = get_last_node(height, rec_height + 1, node->right);
	}
	else
		return (node);

	if (right)
		return (right);
	return (left);
}
/**
 * get_last - finds last node of the tree
 * @root: root node of the tree
 * Return: last node
 */
heap_t *get_last(heap_t *root)
{
	int height;

	height = get_height(root);

	return (get_last_node(height, 1, root));
}
/**
 * heap_extract - extracts root node of Max Binary Heap
 * @root: double ptr to root node of heap
 * Return: 0 on fail or value stored in root node
 */
int heap_extract(heap_t **root)
{
	heap_t *temp;
	int swap;

	if (!*root)
		return (0);

	if (!(*root)->left && !(*root)->right)
	{
		swap = (*root)->n;
		free(*root);
		*root = NULL;
		return (swap);
	}
	temp = get_last(*root);
	if (temp->parent->right)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;

	swap = (*root)->n;
	(*root)->n = temp->n;

	move_node(*root);

	free(temp);
	return (swap);
}
