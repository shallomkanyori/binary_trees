#include "binary_trees.h"

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * @leaf_depth: pointer to depth all leaves should be
 * @depth: the current depth
 *
 * Return: 1 if tree is perfect. 0 if not or if tree is NULL.
 */
int is_perfect(const binary_tree_t *tree, int *leaf_depth, int depth)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (*leaf_depth == -1)
			*leaf_depth = depth;

		return (depth == *leaf_depth ? 1 : 0);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	left = is_perfect(tree->left, leaf_depth, depth + 1);
	right = is_perfect(tree->right, leaf_depth, depth + 1);

	return ((left == 1 && right == 1) ? 1 : 0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect. 0 if not or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_depth = -1;

	if (tree == NULL)
		return (0);

	return (is_perfect(tree, &leaf_depth, 0));
}
