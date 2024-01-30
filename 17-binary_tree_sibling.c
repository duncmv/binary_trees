#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to a node
 *
 * Return: pointer to the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left, *right;

	if (node && node->parent)
	{
		left = node->parent->left;
		right = node->parent->right;

		if (right && right->n == node->n) /* node is right */
			return (left);

		if (left && left->n == node->n)
			return (right);
	}
	return (NULL);
}
