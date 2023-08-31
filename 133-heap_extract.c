#include "binary_trees.h"

/**
 * q_insert - inserts a node into a queue
 * @node: pointer to the binary tree node to insert
 * @last: double pointer to the end of the queue
 *
 * Return: pointer to the new queue node. NULL on failure.
 */
q_t *q_insert(binary_tree_t *node, q_t **last)
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
 * heap_last - gets the last level-order child of a heap
 * @root: pointer to the root node of the heap
 *
 * Return: a pointer to the last level-order child of the heap. NULL on failure
 */
heap_t *heap_last(heap_t *root)
{
	q_t *head = NULL, *tail = NULL, *tmp = NULL;
	int left = 1, right = 1;
	heap_t *res = NULL;

	head = q_insert(root, &tail);
	while (head)
	{
		if (head->node->left)
			left = q_insert(head->node->left, &tail) != NULL;

		if (left && head->node->right)
			right = q_insert(head->node->right, &tail) != NULL;

		if (!left || !right)
		{
			while (head)
			{
				tmp = head;
				head = head->next;
				free(tmp);
			}

			return (NULL);
		}

		if (head->next == NULL)
			break;

		tmp = head;
		head = head->next;
		free(tmp);
	}

	res = tail->node;
	free(head);
	tail = NULL;

	return (res);
}

/**
 * heap_swap - swaps a node with its parent in a max binary heap
 * @root: double pointer to the root node of the heap
 * @node: pointer to the node
 * @p: pointer to the parent node
 */
void heap_swap(heap_t **root, heap_t *node, heap_t *p)
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
 * heapify_down - down-heaps a max binary heap
 * @root: double pointer to the root node of the heap
 * @node: pointer to the root node of the subtree to down-heap
 */
void heapify_down(heap_t **root, heap_t *node)
{
	heap_t *left, *right, *largest;

	if (root == NULL || node == NULL)
		return;

	left = node->left;
	right = node->right;
	largest = node;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		heap_swap(root, largest, node);
		heapify_down(root, node);
	}
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to the root node of the heap
 *
 * Return: the value of the root node.
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *r;
	int res = 0;

	if (root == NULL || *root == NULL)
		return (res);

	r = *root;
	res = r->n;
	last = heap_last(r);
	if (last == NULL)
		return (0);

	if (last->parent == NULL)
	{
		free(r);
		*root = NULL;
		return (res);
	}
	else if (last == last->parent->left)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	last->parent = NULL;
	last->left = r->left;
	if (r->left)
		r->left->parent = last;

	last->right = r->right;
	if (r->right)
		r->right->parent = last;

	heapify_down(root, last);
	free(r);

	return (res);
}
