#include "binary_trees.h"

/**
 * to_avl - builds an AVL tree from a sorted array
 * @array: the array
 * @start: the start index of the array
 * @end: the end index of the array
 *
 * Return: a pointer to the root node of the new AVL tree or NULL on failure.
 */
avl_t *to_avl(int *array, int start, int end)
{
	int mid;
	avl_t *root = NULL, *l = NULL, *r = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	l = to_avl(array, start, mid - 1);
	root->left = l;
	if (l)
		l->parent = root;

	r = to_avl(array, mid + 1, end);
	root->right = r;
	if (r)
		r->parent = root;

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: the array
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the new AVL tree or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (to_avl(array, 0, (int)(size - 1)));
}
