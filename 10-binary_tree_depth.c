#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree node
 * @tree: pointer to the node
 *
 * Return: the depth of the node. 0 if it is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *p = tree;
	size_t res = 0;

	if (tree == NULL)
		return (0);

	p = p->parent;
	while (p)
	{
		res++;
		p = p->parent;
	}

	return (res);
}
