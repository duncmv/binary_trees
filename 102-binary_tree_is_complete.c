#include "binary_trees.h"
#include "limits.h"
static int partial_complete(const binary_tree_t *tree);

/**
 * gaps - checks if leafs level align
 * @tree: pointer to a binary tree
 *
 * Return: 1 for true and 0 for false
 */
static int gaps(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right == NULL)
		return (1 + gaps(tree->left));
	return (gaps(tree->left) + gaps(tree->right));
}

/**
 * partial_complete - Internal nodes can have 0, 1, or 2 children
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 */
static int partial_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left)
	{
		if (tree->right == NULL && tree->left->left)
			return (0);
		if (tree->right == NULL && tree->left->right)
			return (0);
		/* return (1); */
	}
	else if (tree->right && tree->left == NULL)
		return (0);

	return (partial_complete(tree->left) && partial_complete(tree->right));
}

/**
 * max - get the max of two integers
 * @x: first int
 * @y: second int
 * @min: should the min be returned instead: 1 for true 0 for false
 *
 * Return: the the greater of the two integers
 */
size_t max(size_t x, size_t y, int min)
{
	if (min && x > y)
		return (y);
	if (x > y)
		return (x);
	return (y);
}

/**
 * longest_path - the height of a tree
 * @tree: pointer to a tree
 *
 * Return: the height of a binary tree
 */
size_t longest_path(const binary_tree_t *tree)
{
	size_t lh;
	size_t rh;

	if (tree)
	{
		rh = tree->left ? 1 + longest_path(tree->left) : 1;
		lh = tree->right ? 1 + longest_path(tree->right) : 1;
		return (max(lh, rh, 0));
	}
	return (0);
}

/**
 * shortest_path - the height of a tree
 * @tree: pointer to a tree
 *
 * Return: the height of a binary tree
 */
size_t shortest_path(const binary_tree_t *tree)
{
	size_t lh;
	size_t rh;

	if (tree)
	{
		rh = tree->left ? 1 + shortest_path(tree->left) : 1;
		lh = tree->right ? 1 + shortest_path(tree->right) : 1;
		return (max(lh, rh, 1));
	}
	return (0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 for true and 0 for false
 * A complete Binary Tree:
 * 1. All the leafs must be on the same level
 * 2. Internal nodes can have 0, 1, or 2 children
 *
 * HOW
 * If a node is leaf, get its depth.
 * No two leafs can have different depths
 * Ensure the height is logarithmic with the number of nodes
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int longest, shortest;

	if (!partial_complete(tree))
		return (0); /* All leafs aren't on the same level */

	longest = (int)longest_path(tree);
	shortest = (int)shortest_path(tree);
	if (longest - shortest > 1 || longest - shortest < -1)
		return (0);
	if (gaps(tree) > 1)
		return (0);
	return (1);
}
