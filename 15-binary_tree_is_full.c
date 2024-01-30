#include "binary_trees.h"

/**
 * is_full -  checks if a binary tree is full
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 *
 */
int is_full(const binary_tree_t *tree)
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
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full(tree));
}
