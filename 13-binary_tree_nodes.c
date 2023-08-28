#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least 1 child in binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes with at least 1 child. 0 if it is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	return (1 + left + right);
}
