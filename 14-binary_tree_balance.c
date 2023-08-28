#include "binary_trees.h"

/**
 * binary_tree_height1 - measures the height of a binary tree, leaf height = 1
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree. 0 if it is NULL.
 */
int binary_tree_height1(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_height1(tree->left);
	right = binary_tree_height1(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the balance factor of the tree. 0 if it is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height1(tree->left);
	right_h = binary_tree_height1(tree->right);

	return (left_h - right_h);
}
