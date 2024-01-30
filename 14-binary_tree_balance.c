#include "binary_trees.h"

/**
 * max - get the max of two integers
 * @x: first int
 * @y: second int
 *
 * Return: the the greater of the two integers
 */
size_t max(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

/**
 * th - the height of a tree
 * @tree: pointer to a tree
 *
 * Return: the height of a binary tree
 */
size_t th(const binary_tree_t *tree)
{
	size_t lh;
	size_t rh;

	if (tree)
	{
		rh = tree->left ? 1 + th(tree->left) : 1;
		lh = tree->right ? 1 + th(tree->right) : 1;
		return max(lh, rh);
	}
	return (0);
}

/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 * @tree: pointer to a binary tree
 *
 * Return: the number of actual nodes in the tree
 * BF=height(left_subtree)−height(right_subtree)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int BF; /* Balance Factor */

	if (tree == NULL)
		return (0);

	/*
	 * BF measures how widely the heights of left and right
	 * substrees differ
	 * BF of 0 means the heights are equal at that node or tree depth
	 * BF > +1 or less than -1 indicates a significant imbalance
	 */
	BF = th(tree->left) - th(tree->right);

	return (BF);
}
