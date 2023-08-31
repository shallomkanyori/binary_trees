#include "binary_trees.h"

/**
 * heap_delete - deletes an entire max binary heap tree
 * @tree: pointer to the root node of the tree
 *
 * Return: nothing.
 */
void heap_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	heap_delete(tree->left);
	heap_delete(tree->right);
	free(tree);
}

/**
 * array_to_heap - builds a max binary heap tree from an array
 * @array: the array
 * @size: the size of the array
 *
 * Return: a pointer to the root node of the heap or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (heap_insert(&root, array[i]) == NULL)
		{
			heap_delete(root);
			return (NULL);
		}
	}

	return (root);
}
