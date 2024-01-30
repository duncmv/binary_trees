#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to a binary tree
 *
 * Return: the number of actual nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	/* returning 1 + the counts from both left and right subtrees  */
	if (tree && (tree->left || tree->right))
	{
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	}

	return (0); /* tree is NULL or both left and right are NULL */
}
