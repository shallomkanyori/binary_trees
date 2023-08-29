#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST
 * @value: the value to look for
 *
 * Return: a pointer to the node containing value. NULL if not found or if
 * tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *curr;

	if (tree == NULL)
		return (NULL);

	curr = (bst_t *)tree;

	while (curr && curr->n != value)
	{
		if (curr->n > value)
			curr = curr->left;
		else
			curr = curr->right;
	}

	return (curr);
}
