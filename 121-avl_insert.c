#include "binary_trees.h"
#include <stdlib.h>

/**
 * rotate_left - left rotates a subtree to balance an AVL tree
 * @node: pointer to the pivot node
 * @p: pointer to the root node of the subtree
 * @n_bf: the balance factor of the node
 *
 * Return: the new root node of the rotated subtree.
 */
avl_t *rotate_left(avl_t *node, avl_t *p, int n_bf)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;

	if (n_bf > 0)
	{
		c_root = binary_tree_rotate_right(node);
		p->right = c_root;
		c_root->parent = p;
		r_root = binary_tree_rotate_left(p);
	}
	else
	{
		r_root = binary_tree_rotate_left(p);
	}

	return (r_root);
}

/**
 * rotate_right - right rotates a subtree to balance an AVL tree
 * @node: pointer to the pivot node
 * @p: pointer to the root node of the subtree
 * @n_bf: the balance factor of the node
 *
 * Return: the new root node of the rotated subtree.
 */
avl_t *rotate_right(avl_t *node, avl_t *p, int n_bf)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;

	if (n_bf < 0)
	{
		c_root = binary_tree_rotate_left(node);
		p->left = c_root;
		c_root->parent = p;
		r_root = binary_tree_rotate_right(p);
	}
	else
	{
		r_root = binary_tree_rotate_right(p);
	}

	return (r_root);
}

/**
 * avl_balance - balances an AVL tree after an insertion
 * @tree: double pointer to the root node of the tree
 * @node: pointer to the node that was inserted
 */
void avl_balance(avl_t **tree, avl_t *node)
{
	avl_t *p, *gp = NULL, *r_root = NULL;
	int n_bf, p_bf;

	if (tree == NULL || node == NULL)
		return;

	for (p = node->parent; p; p = node->parent)
	{
		n_bf = binary_tree_balance(node);
		p_bf = binary_tree_balance(p);

		if (p_bf == 0)
			break;

		if (abs(p_bf) <= 1)
		{
			node = p;
			continue;
		}

		gp = p->parent;
		if (node == p->right && p_bf < -1)
			r_root = rotate_left(node, p, n_bf);
		else if (p_bf > -1)
			r_root = rotate_right(node, p, n_bf);

		r_root->parent = gp;
		if (gp != NULL)
		{
			if (p == gp->left)
				gp->left = r_root;
			else
				gp->right = r_root;
		}
		else
		{
			*tree = r_root;
		}
		break;
	}
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: the value to insert
 *
 * Return: a pointer to the new node. NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *curr;
	avl_t *p = NULL;

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

	avl_balance(tree, new);

	return (new);
}
