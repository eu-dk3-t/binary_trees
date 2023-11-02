#include "binary_trees.h"

/**
 * traverse - Traverses a binary tree
 * @node: Pointer to the current node.
 * @height: Pointer to the height of the tree.
 *
 * Return: 1 if it is a leaf node or the node is full, 0 otherwise.
 */
char traverse(const binary_tree_t *node, size_t *height)
{
	size_t left_h, right_h;

	left_h = *height;
	right_h = *height;

	if (node == NULL)
	{
		(*height)--;
		return (0);
	}

	if ((node->left == NULL) ^ (node->right == NULL))
		return (0);

	left_h++;
	right_h++;
	if (traverse(node->left, &left_h) ^ traverse(node->right, &right_h))
		return (0);

	if (left_h > right_h)
		*height = left_h;
	else
		*height = right_h;

	if (left_h != right_h)
		return (0);
	return (1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);
	return ((int) traverse(tree, &height));
}
