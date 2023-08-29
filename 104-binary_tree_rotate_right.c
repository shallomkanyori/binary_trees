#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: a pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL)
		return (NULL);

	pivot = tree->left;
	if (pivot == NULL)
		return (NULL);

	tree->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = tree;

	pivot->right = tree;
	tree->parent = pivot;

	pivot->parent = NULL;
	tree = pivot;

	return (tree);
}
