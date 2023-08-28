#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is leaf. 0 if not or if node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int res = 0;

	if (node && node->left == NULL && node->right == NULL)
		res = 1;

	return (res);
}
