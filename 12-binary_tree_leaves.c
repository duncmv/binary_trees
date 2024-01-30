#include "binary_trees.h"

/**
 * binary_tree_leaves -  counts the leaves in a binary tree
 * @tree: pointer to a binary tree
 *
 * Return: the number of leaf nodes in on the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1); /* returning 1 indicates 1 count of a leaf node */

	return (/* return the counts from both left and right subtrees */
		binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
