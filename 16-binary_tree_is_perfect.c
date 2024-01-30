#include "binary_trees.h"

/**
 * power - the pow implementation
 * @base: base
 * @exponent: the exponent
 *
 * Return: the power
 */
double power(double base, int exponent)
{
	double result = 1.0;

	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}

	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result *= base;
		base *= base;
		exponent /= 2;
	}

	return result;
}

/**
 * is_perfect -   checks if a binary tree is perfect
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 *
 */
int is_perfect(const binary_tree_t *tree)
{
	/**
	 * A binary tree is perfect if all nodes internal nodes (non-leafs)
	 * are completely filled unless of course they're external nodes
	 * (leafs to be precise).
	 * Also, number of nodes = 2^(height + 1)-1
	 * If this last property isn't satisfied, it's not a perfect tree
	 */
	size_t tree_size, tree_height;

	tree_size = binary_tree_size(tree);
	tree_height = binary_tree_height(tree);
	if (tree_size != power(2, (tree_height + 1)) - 1)
		return (0);
	if (!binary_tree_is_full(tree))
		return (0);
	return (1);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is full, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect(tree));
}
