#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is a root
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a root. 0 if not or if node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int res = (node && node->parent == NULL) ? 1 : 0;

	return (res);
}
