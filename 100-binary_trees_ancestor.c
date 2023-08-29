#include "binary_trees.h"

/**
 * depth - gets the depth of a binary tree node
 * @node: pointer to the node
 *
 * Return: the depth of the node. 0 if it is NULL.
 */
int depth(const binary_tree_t *node)
{
	int res = 0;

	while (node)
	{
		res++;
		node = node->parent;
	}

	return (res);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor of first and second.
 * NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int depth1 = 0, depth2 = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	depth1 = depth(first);
	depth2 = depth(second);

	for (; depth1 > depth2; depth1--)
		first = first->parent;

	for (; depth2 > depth1; depth2--)
		second = second->parent;

	while (first && second)
	{
		if (first == second)
		{
			return ((binary_tree_t *)(first));
		}

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
