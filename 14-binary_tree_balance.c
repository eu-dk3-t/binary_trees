#include "binary_trees.h"

/**
 * binary_tree_height - gets the height of a binary tree
 * @tree: root node to draw height from for tree
 *
 * Return: size_t representing height, 0 on failure or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t l_size = 0;
        size_t r_size = 0;

        if (!tree)
                return (0);

        l_size += (tree->left) ? 1 + binary_tree_height(tree->left) : 0;
        r_size += (tree->right) ? 1 + binary_tree_height(tree->right) : 0;
        return ((l_size > r_size) ? l_size : r_size);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
