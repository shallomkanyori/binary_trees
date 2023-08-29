#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: a pointer to the new root node of the tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL)
		return (NULL);

	pivot = tree->right;
	if (pivot == NULL)
		return (NULL);

	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	pivot->left = tree;
	tree->parent = pivot;

	pivot->parent = NULL;
	tree = pivot;

	return (tree);
}
