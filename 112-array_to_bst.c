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
 * remove_duplicates - removes duplicates in array
 * @arr: the array
 * @s: the size of the array
 *
 * Return: the new size of the array.
 */
size_t remove_duplicates(int *arr, size_t s)
{
	size_t i, j, k;

	for (i = 0; arr && i < (s - 1); i++)
	{
		for (j = (i + 1); j < s; j++)
		{
			if (arr[i] == arr[j])
			{
				for (k = (j + 1); k < s; k++)
					arr[k - 1] = arr[k];
				s--;
				j--;
			}
		}
	}

	return (s);
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
	int *arr_cpy;
	size_t i;

	if (array == NULL)
		return (NULL);

	arr_cpy = malloc(sizeof(int) * size);
	if (arr_cpy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr_cpy[i] = array[i];

	size = remove_duplicates(arr_cpy, size);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, arr_cpy[i]) == NULL)
		{
			bst_delete(root);
			return (NULL);
		}
	}

	free(arr_cpy);

	return (root);
}
