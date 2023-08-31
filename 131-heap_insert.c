#include "binary_trees.h"

/**
 * queue_insert - inserts a node into a queue
 * @node: pointer to the binary tree node to insert
 * @last: double pointer to the end of the queue
 *
 * Return: pointer to the new queue node. NULL on failure.
 */
q_t *queue_insert(binary_tree_t *node, q_t **last)
{
	q_t *new;

	if (node == NULL || last == NULL)
		return (NULL);

	new = malloc(sizeof(q_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;
	if (*last == NULL)
		*last = new;
	else
	{
		(*last)->next = new;
		*last = new;
	}

	return (new);
}

/**
 * queue_delete - deletes a queue
 * @first: pointer to the head of the queue
 */
void queue_delete(q_t *first)
{
	q_t *tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
}

/**
 * swap - swaps a node with its parent in a max binary heap
 * @root: double pointer to the root node of the heap
 * @node: pointer to the node
 * @p: pointer to the parent node
 */
void swap(heap_t **root, heap_t *node, heap_t *p)
{
	heap_t *gp, *tl, *tr;

	gp = p->parent;
	node->parent = gp;
	p->parent = node;
	if (gp == NULL)
		*root = node;
	else if (p == gp->left)
		gp->left = node;
	else
		gp->right = node;

	tl = node->left;
	tr = node->right;

	if (node == p->left)
	{
		node->left = p;
		node->right = p->right;
		if (p->right)
			p->right->parent = node;
	}
	else
	{
		node->right = p;
		node->left = p->left;
		if (p->left)
			p->left->parent = node;
	}

	p->left = tl;
	if (tl)
		tl->parent = p;

	p->right = tr;
	if (tr)
		tr->parent = p;
}

/**
 * heapify - heapifies a max binary heap after insertion
 * @root: double pointer to the root node of the max heap
 * @node: pointer to the newly inserted node
 */
void heapify(heap_t **root, heap_t *node)
{
	heap_t *p;

	if (root == NULL || node == NULL)
		return;

	p = node->parent;
	while (p)
	{
		if (p->n >= node->n)
			break;

		swap(root, node, p);
		p = node->parent;
	}
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the heap
 * @value: the value of the node to insert
 *
 * Return: a pointer to the new node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *p = NULL;
	q_t *first = NULL, *last = NULL, *tmp = NULL;

	if (root == NULL)
		return (NULL);

	first = queue_insert(*root, &last);
	while (first)
	{
		p = first->node;
		if (p->left == NULL || p->right == NULL)
		{
			queue_delete(first);
			break;
		}

		if (queue_insert(p->left, &last) == NULL ||
			queue_insert(p->right, &last) == NULL)
		{
			queue_delete(first);
			return (NULL);
		}

		tmp = first->next;
		free(first);
		first = tmp;
	}

	new = binary_tree_node(p, value);
	if (new == NULL)
		return (NULL);
	if (p == NULL)
		*root = new;
	else if (p->left == NULL)
		p->left = new;
	else
		p->right = new;

	heapify(root, new);
	return (new);
}
