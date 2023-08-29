#include "binary_trees.h"

/**
 * _search - searches for a value in a BST
 * @tree: pointer to the root node of the BST
 * @value: the value to look for
 *
 * Return: a pointer to the node containing value. NULL if not found or if
 * tree is NULL.
 */
bst_t *_search(const bst_t *tree, int value)
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

/**
 * bst_successor - finds the in-order successor of a node in a BST
 * @node: pointer to the node
 *
 * Return: pointer to the successor. NULL if not found or if node is NULL.
 */
bst_t *bst_successor(bst_t *node)
{
	bst_t *p;

	if (node->right != NULL)
	{
		node = node->right;

		while (node->left)
			node = node->left;

		return (node);
	}

	p = node->parent;
	while (p && node == p->right)
	{
		node = p;
		p = p->parent;
	}

	return (p);
}

/**
 * shift_nodes- replaces one node with another in a BST
 * @tree: double pointer to the root node of the BST
 * @n1: pointer to the node to replace
 * @n2: pointer to the replacement node;
 */
void shift_nodes(bst_t **tree, bst_t *n1, bst_t *n2)
{
	if (tree == NULL || n1 == NULL)
		return;

	if (n1->parent == NULL)
		*tree = n2;
	else if (n1 == n1->parent->left)
		n1->parent->left = n2;
	else
		n1->parent->right = n2;

	if (n2 != NULL)
		n2->parent = n1->parent;
}

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node of the BST
 * @value: the value of the node to remove
 *
 * Return: a pointer to the root node of the updated BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *succ;

	if (root == NULL)
		return (NULL);

	node = _search(root, value);
	if (node == NULL)
		return (NULL);

	if (node->left == NULL)
		shift_nodes(&root, node, node->right);
	else if (node->right == NULL)
		shift_nodes(&root, node, node->left);
	else
	{
		succ = bst_successor(node);
		if (succ->parent != node)
		{
			shift_nodes(&root, succ, succ->right);
			succ->right = node->right;
			succ->right->parent = succ;
		}
		shift_nodes(&root, node, succ);
		succ->left = node->left;
		succ->left->parent = succ;
	}

	free(node);

	return (root);
}
