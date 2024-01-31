#include "binary_trees.h"
#include <limits.h>
/**
 * find_max - finds the max value of a binary tree
 * @tree: pointer to root of tree to be checked
 *
 * Return: max value in a binary tree
*/
int find_max(const binary_tree_t *tree)
{
	int max_value, left_max, right_max;

	if (tree == NULL)
		return (INT_MIN);

	max_value = tree->n;


	left_max = find_max(tree->left);
	if (left_max > max_value)
		max_value = left_max;


	right_max = find_max(tree->right);
	if (right_max > max_value)
		max_value = right_max;

	return (max_value);
}
/**
 * find_min - finds the min value of a binary tree
 * @tree: pointer to root of tree to be checked
 *
 * Return: min value in a binary tree
*/
int find_min(const binary_tree_t *tree)
{
	int min_value, left_min, right_min;

	if (tree == NULL)
		return (INT_MAX);

	min_value = tree->n;


	left_min = find_min(tree->left);
	if (left_min < min_value)
		min_value = left_min;


	right_min = find_min(tree->right);
	if (right_min < min_value)
		min_value = right_min;

	return (min_value);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a BST
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if is a BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_max, right_min, left_sub, right_sub, root;

	if (tree == NULL)
		return (0);
	root = tree->n;

	if (tree->left)
	{
		left_max = find_max(tree->left);
		if (left_max > root)
			return (0);
	}

	if (tree->right)
	{
		right_min = find_min(tree->right);
		if (right_min < root)
			return (0);
	}

	/*checking sub trees*/
	left_sub = right_sub = 1;
	if (tree->left)
		left_sub = binary_tree_is_bst(tree->left);
	if (tree->right)
		right_sub = binary_tree_is_bst(tree->right);

	return (left_sub && right_sub);
}
