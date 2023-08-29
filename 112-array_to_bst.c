#include "binary_trees.h"

/**
 * bst_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: nothing.
 */
void bst_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	bst_delete(tree->left);
	bst_delete(tree->right);
	free(tree);
}

/**
 * array_to_bst - builds a BST from an array
 * @array: the array
 * @size: the size of the array
 *
 * Return: a pointer to the root node of the BST or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; array && i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			bst_delete(root);
			return (NULL);
		}
	}

	return (root);
}
