#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * is_avl - checks if a binary_tree is a valid AVL tree
 * @tree: pointer to the root node of the subtree
 * @min: the minimum value the node can be
 * @max: the maximum value the node can be
 *
 * Return: The height of the tree if tree is a valid AVL tree. -1 otherwise.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int l, r;

	if (tree == NULL)
		return (0);

	if (tree->n < min || tree->n > max)
		return (-1);

	l = is_avl(tree->left, min, tree->n - 1);
	if (l == -1)
		return (-1);

	r = is_avl(tree->right, tree->n + 1, max);
	if (r == -1)
		return (-1);

	if (abs(l - r) > 1)
		return (-1);

	return (l > r ? l + 1 : r + 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL tree. 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX) == -1 ? 0 : 1);
}
