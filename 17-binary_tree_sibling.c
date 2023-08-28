#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node
 *
 * Return: pointer to the sibling node or NULL if node is NULL, parent is NULL
 * or node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *p;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	p = node->parent;

	if (node == p->left)
		return (p->right);

	return (p->left);
}
