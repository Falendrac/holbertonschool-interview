#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - binary that measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_size(const heap_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right) + 1;

	return (left_size + right_size);
}

/**
 * getNodeFromIndex - Finds the node at the given index
 *
 * @root: Pointer to the root node of the tree
 * @index: Index of the node to find
 *
 * Return: Pointer to the node at the given index
 */
heap_t *getNodeFromIndex(heap_t *root, int index)
{
	int parentIndex, direction;

	if (index == 0)
		return (root);

	parentIndex = (index - 1) / 2;
	direction = (index - 1) % 2;

	return (getNodeFromIndex(direction ? root->right : root->left, parentIndex));
}

/**
 * swap - Swaps the values of two nodes
 *
 * @src: Pointer to the source node
 * @dest: Pointer to the destination node
 */
void swap(heap_t *src, heap_t *dest)
{
	int tmp;

	tmp = dest->n;
	dest->n = src->n;
	src->n = tmp;
	src = dest;
	dest = src->parent;
}

/**
 * heap_insert - insert a node in the good place
 *
 * @root: The root of the binary tree
 * @value: Value set in the new node
 * Return: New node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	int size, index;

	if (root == NULL)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	size = binary_tree_size(*root);
	index = (size - 1) / 2;
	parent = getNodeFromIndex(*root, index);
	new->parent = parent;

	if (size % 2 == 0)
		parent->right = new;
	else
		parent->left = new;

	while (parent && parent->n < new->n)
		swap(new, parent);

	return (new);
}
