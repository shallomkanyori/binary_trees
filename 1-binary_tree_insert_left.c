#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert in
 * @value: the value of the node
 *
 * Return: a pointer to the new node or NULL on failure or if the parent
 * is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->right = NULL;
	new->left = parent->left;
	if (parent->left)
		parent->left->parent = new;

	parent->left = new;
	new->parent = parent;

	return (new);
}
