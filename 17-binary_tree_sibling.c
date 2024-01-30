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

	return (result);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to root node
 * Return: height of tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to a binary tree
 *
 * Return: the size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size(tree->left) +
		tree_size(tree->right));
}

/**
 * is_full -  checks if a binary tree is full
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 */
static int is_full(const binary_tree_t *tree)
{
	/**
	 * A binary tree is full if each node has extacly 0 or two children.
	 * There is no node with only left or right child.
	 * They either have both or none at all
	 */
	if (tree == NULL)
		return (1);

	if (tree->left && tree->right == NULL)
		return (0);
	else if (tree->right && tree->left == NULL)
		return (0);

	return (is_full(tree->left) && is_full(tree->right));
}

/**
 * binary_tree_is_perfect -   checks if a binary tree is perfect
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/**
	 * A binary tree is perfect if all nodes internal nodes (non-leafs)
	 * are completely filled unless of course they're external nodes
	 * (leafs to be precise).
	 * Also, number of nodes = 2^(height + 1)-1
	 * If this last property isn't satisfied, it's not a perfect tree
	 */
	size_t t_size, t_height;

	t_size = tree_size(tree);
	t_height = tree_height(tree);
	if (t_size != power(2, (t_height + 1)) - 1)
		return (0);
	if (!is_full(tree))
		return (0);
	return (1);
}
