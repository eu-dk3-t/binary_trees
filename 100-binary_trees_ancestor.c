#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *par1, *par2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	par1 = first->parent, par2 = second->parent;
	if (first == par2 || !par1 || (!par1->parent && par2))
		return (binary_trees_ancestor(first, par2));
	else if (par1 == second || !par2 || (!par2->parent && par1))
		return (binary_trees_ancestor(par1, second));
	return (binary_trees_ancestor(par1, par2));
}
