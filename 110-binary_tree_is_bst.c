#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - checks if a binary_tree is a valid BST
 * @tree: pointer to the root node of the subtree
 * @min: the minimum value the node can be
 * @max: the maximum value the node can be
 *
 * Return: 1 if tree is a valid BST. 0 othrewise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	int l, r;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	l = is_bst(tree->left, min, tree->n - 1);
	r = is_bst(tree->right, tree->n + 1, max);

	return ((l == 1 && r == 1) ? 1 : 0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST. 0 othrewise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
