#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of leaves in the tree. 0 if it is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	return (left + right);
}
