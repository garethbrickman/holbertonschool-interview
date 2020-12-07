#include<limits.h>
#include<stddef.h>
#include "binary_trees.h"


int bst_util(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - Checks if a tree is a BST
 * @tree: ptr to root node
 *
 * Return: 1 if is a BST, 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_util(tree, INT_MIN, INT_MAX));
}

/**
 * bst_util - Checks if a tree is a BST
 * @tree: ptr to root node
 * @min: minimum constraint
 * @max: maximum constraint
 *
 * Return: 1 if is a BST, 0 if not
 */

int bst_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_util(tree->left, min, tree->n - 1) &&
		bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures height of binary tree
 * @tree: pointer to root
 *
 * Return: size_t height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r_count, l_count;

	if (tree == NULL)
		return (0);

	if (!tree->right && !tree->left)
		return (0);

	r_count = binary_tree_height(tree->right);
	l_count = binary_tree_height(tree->left);

	if (l_count > r_count)
		return (l_count + 1);
	else
		return (r_count + 1);
}

/**
 * binary_tree_is_avl - checks if binary tree is valid AVL tree
 *
 * @tree: ptr to root node
 *
 * Return: 1 if tree valid AVL, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;
	size_t difference;

	if (!tree)
		return (0);
	if (!binary_tree_is_bst(tree))
		return (0);

	height_left = tree->left ? binary_tree_height(tree->left) : 0;
	height_right = tree->right ? binary_tree_height(tree->right) : 0;

	if (height_left > height_right)
		difference = height_left - height_right;
	else
		difference = height_right - height_left;

	if (difference > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
