#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node in a binary tree
 * That is to say that it returns the sibling of its parent
 * @node: pointer to the node whose parent's sibling is returned
 *
 * Return: pointer to the sibling of the node's parent
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left, *right, *parent;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (parent && parent->parent)
	{
		left = parent->parent->left;
		right = parent->parent->right;

		if (right && right->n == parent->n) /* parent is right */
			return (left);

		if (left && left->n == parent->n) /* parent is left */
			return (right);
	}
	return (NULL);
}
