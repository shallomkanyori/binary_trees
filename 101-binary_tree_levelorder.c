#include "binary_trees.h"

/**
 * height - gets the height of a tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree. 0 if it is NULL.
 */
int height(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree == NULL)
		return (0);

	l = height(tree->left);
	r = height(tree->right);

	return ((l > r ? l : r) + 1);

}

/**
 * process_level - processes each binary tree node at a certain level
 * @tree: pointer to the root node of the tree
 * @l: the level to process
 * @func: the function to call for the value of each node
 */
void process_level(const binary_tree_t *tree, int l, void (*func)(int))
{
	if (tree == NULL || l < 0)
		return;

	if (l == 0)
	{
		func(tree->n);
		return;
	}

	process_level(tree->left, l - 1, func);
	process_level(tree->right, l - 1, func);
}

/**
 * binary_tree_levelorder - level-order traverses a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to function to call for the value of each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = height(tree);
	int l;

	for (l = 0; l < h; l++)
		process_level(tree, l, func);
}
