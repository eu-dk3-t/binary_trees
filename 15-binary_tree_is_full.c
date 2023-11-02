#include "binary_trees.h"

/**
 * traverse - Traverses a binary tree
 * @node: Pointer to the current node.
 *
 * Return: 1 if it is a leaf node or the node is full, 0 otherwise.
 */
char traverse(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if ((node->left == NULL) ^ (node->right == NULL))
		return (0);
	if (traverse(node->left) ^ traverse(node->right))
		return (0);
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (traverse(tree));
}
