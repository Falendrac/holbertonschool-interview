#include "binary_trees.h"

/**
 * initBinaryTreeNode - Initializes a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the initialized node
 */
binary_tree_t *initBinaryTreeNode(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * buildAvlArray - Builds an array of AVL nodes from a sorted array
 *
 * @array: Pointer to the sorted array
 * @start: Start index of the array
 * @end: End index of the array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the AVL tree
 */
avl_t *buildAvlArray(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *tree = NULL;
	size_t middle;

	middle = (start + end) / 2;
	tree = initBinaryTreeNode(parent, array[middle]);

	if (tree == NULL)
		return (NULL);

	if (start > end)
		return (NULL);

	if (middle > start)
		tree->left = buildAvlArray(array, start, middle - 1, tree);

	if (middle < end)
		tree->right = buildAvlArray(array, middle + 1, end, tree);

	return (tree);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the sorted array
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || !size)
		return (NULL);

	tree = buildAvlArray(array, 0, size - 1, NULL);

	return (tree);
}
