#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node of the BST
 * @value: the value to insert
 *
 * Return: a pointer to the new node. NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *curr;
	bst_t *p = NULL;

	if (tree == NULL)
		return (NULL);

	curr = *tree;
	while (curr)
	{
		p = curr;
		if (value == curr->n)
			return (NULL);
		else if (value < curr->n)
			curr = curr->left;
		else
			curr = curr->right;
	}

	new = binary_tree_node(p, value);
	if (new == NULL)
		return (NULL);

	if (p == NULL)
		*tree = new;
	else if (new->n < p->n)
		p->left = new;
	else
		p->right = new;

	return (new);
}
