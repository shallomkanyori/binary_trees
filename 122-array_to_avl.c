#include "binary_trees.h"

/**
 * avl_delete - deletes an entire AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Return: nothing.
 */
void avl_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	avl_delete(tree->left);
	avl_delete(tree->right);
	free(tree);
}

/**
 * remove_duplicates - returns copy of array with duplicates removed
 * @arr: the array
 * @s: pointer to the size of the array
 *
 * Return: the new array. NULL on failure.
 */
int *remove_duplicates(int *arr, size_t *s)
{
	size_t i, j, u_ind = 0;
	size_t size;
	int *arr_cpy;
	int is_dup = 0;

	if (arr == NULL || s == NULL)
		return (NULL);

	size = *s;

	arr_cpy = malloc(sizeof(int) * size);
	if (arr_cpy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		is_dup = 0;
		for (j = 0; j < u_ind; j++)
		{
			if (arr[i] == arr[j])
			{
				is_dup = 1;
				break;
			}
		}

		if (!is_dup)
		{
			arr_cpy[u_ind] = arr[i];
			u_ind++;
		}
	}

	*s = u_ind;

	return (arr_cpy);
}

/**
 * array_to_avl - builds a BST from an array
 * @array: the array
 * @size: the size of the array
 *
 * Return: a pointer to the root node of the AVL tree or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int *arr_cpy;
	size_t i, new_size =  size;

	if (array == NULL || size == 0)
		return (NULL);

	arr_cpy = remove_duplicates(array, &new_size);

	for (i = 0; i < new_size; i++)
	{
		if (avl_insert(&root, arr_cpy[i]) == NULL)
		{
			avl_delete(root);
			return (NULL);
		}
	}

	free(arr_cpy);

	return (root);
}
