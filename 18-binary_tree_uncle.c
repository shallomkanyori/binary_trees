#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node
 *
 * Return: pointer to the uncle node or NULL if node is NULL or node has no
 * uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *p, *gp;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	p = node->parent;
	if (p->parent == NULL)
		return (NULL);

	gp = p->parent;
	if (p == gp->left)
		return (gp->right);

	return (gp->left);
}
