#include "binary_trees.h"

/**
 * traverse - Traverse the binary tree for the valid level to print.
 * @node: Pointer to the root node of the current tree.
 * @idx: The index of the current node.
 * @max_idx: The last index of the tree in array form.
 *
 * Return: 1 if there was a node on the target level, -1 otherwise.
 */
char traverse(binary_tree_t *node, size_t idx, size_t max_idx)
{
	if (node == NULL)
	{
		if (idx <= max_idx)
			return (0);
		return (1);
	}

	return (traverse(node->left, 2 * idx + 1, max_idx) &&
			traverse(node->right, 2 * idx + 2, max_idx));
}

/**
 * size_ofB - Recursively travel down the left side of a binary tree first.
 * @node: Pointer to the current node.
 *
 * Return: The size of the tree.
 */
size_t size_ofB(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + size_ofB(node->left) + size_ofB(node->right));
}

/**
 * binary_tree_is_complete - Check if the binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size = size_ofB(tree);
	return (traverse((binary_tree_t *)tree, 0, size - 1));
}
