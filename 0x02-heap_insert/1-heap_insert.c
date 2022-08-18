#include "binary_trees.h"

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
	int parentIdx, direction;

	if (index == 0)
		return (root);

	parentIdx = (index - 1) / 2;
	direction = (index - 1) % 2;

	return (getNodeFromIndex(direction ? root->right : root->left, parentIdx));
}

/**
 * swap - Swaps the values of two nodes
 *
 * @node: Pointer to the source node
 * Return: The node
 */
heap_t *swap(heap_t *node)
{
	int temp = 0;

	if (node->parent && node->n > node->parent->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
		return (swap(node->parent));
	}
	return (node);
}

/**
 * heap_insert - Insert a new node
 *
 * @root: Pointer to the root node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int idx, size;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	size = binary_tree_size(*root);
	idx = (size - 1) / 2;
	parent = getNodeFromIndex(*root, idx);
	new_node->parent = parent;

	if (size % 2 == 0)
		parent->right = new_node;
	else
		parent->left = new_node;

	new_node = swap(new_node);

	return (new_node);
}
