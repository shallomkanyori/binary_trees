#include "binary_trees.h"

/**
 * shift_nodes- replaces one node with another in a BST
 * @tree: double pointer to the root node of the BST
 * @n1: pointer to the node to replace
 * @n2: pointer to the replacement node;
 */
void shift_nodes(avl_t **tree, avl_t *n1, avl_t *n2)
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
 * del_rotate_left - left rotates a subtree to balance an AVL tree
 * @sib: pointer to the sibling node of the affected subtree
 * @p: pointer to the root node of the subtree
 * @sib_bf: the balance factor of the sibling node
 *
 * Return: the new root node of the rotated subtree.
 */
avl_t *del_rotate_left(avl_t *sib, avl_t *p, int sib_bf)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;

	if (sib_bf > 0)
	{
		c_root = binary_tree_rotate_right(sib);
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
 * del_rotate_right - right rotates a subtree to balance an AVL tree
 * @sib: pointer to the sibling node of the affected subtree
 * @p: pointer to the root node of the subtree
 * @sib_bf: the balance factor of the sibling node
 *
 * Return: the new root node of the rotated subtree.
 */
avl_t *del_rotate_right(avl_t *sib, avl_t *p, int sib_bf)
{
	avl_t *r_root = NULL;
	avl_t *c_root = NULL;

	if (sib_bf < 0)
	{
		c_root = binary_tree_rotate_left(sib);
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
 * del_avl_balance - balances an AVL tree after a deletion
 * @tree: double pointer to the root node of the tree
 * @node: pointer to the node that was deleted
 * @sib: pointer to the node's sibling
 */
void del_avl_balance(avl_t **tree, avl_t *node, avl_t *sib)
{
	avl_t *p, *gp = NULL;
	int sib_bf, p_bf;

	if (tree == NULL || node == NULL)
		return;

	for (p = node->parent; p; p = gp)
	{
		gp = p->parent;
		p_bf = binary_tree_balance(p);

		if (abs(p_bf) == 1)
			break;

		if (p_bf == 0)
		{
			node = p;
			continue;
		}
		sib = sib ? sib : (node == p->left ? p->right : p->left);
		sib_bf = binary_tree_balance(sib);
		if (node == p->left && p_bf < -1)
			node = del_rotate_left(sib, p, sib_bf);
		else if (p_bf > -1)
			node = del_rotate_right(sib, p, sib_bf);

		node->parent = gp;
		if (gp != NULL)
		{
			if (p == gp->left)
				gp->left = node;
			else
				gp->right = node;
		}
		else
			*tree = node;
		sib = NULL;
		if (sib_bf == 0)
			break;
	}
}

/**
 * avl_remove - removes a node from a BST
 * @root: pointer to the root node of the BST
 * @value: the value of the node to remove
 *
 * Return: a pointer to the root node of the updated BST.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *succ, *sub, *sib;

	if (root == NULL)
		return (NULL);

	node = root;
	while (node && node->n != value)
		if (node->n > value)
			node = node->left;
		else
			node = node->right;
	if (node == NULL)
		return (NULL);
	sub = node->parent;
	sib = sub ? (node == sub->left ? sub->right : sub->left) : NULL;
	if (node->left == NULL)
		shift_nodes(&root, node, node->right);
	else if (node->right == NULL)
		shift_nodes(&root, node, node->left);
	else
	{
		succ = node->right;
		while (succ->left)
			succ = succ->left;

		if (succ->parent != node)
		{
			sub = succ->parent;
			sib = sub ? (node == sub->left ? sub->right : sub->left) : NULL;
			shift_nodes(&root, succ, succ->right);
			succ->right = node->right;
			succ->right->parent = succ;
		}
		shift_nodes(&root, node, succ);
		succ->left = node->left;
		succ->left->parent = succ;
	}
	del_avl_balance(&root, node, sib);
	free(node);
	return (root);
}
