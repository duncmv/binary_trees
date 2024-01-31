#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to a binary tree
 *
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
/**
 * tree_preorder - goes through a binary tree using pre-order traversal
 * @array: array to store node values
 * @index: index of array
 * @tree: pointer to the root node of the tree
 * @func: pointer to helper function
*/
void tree_preorder(int *array, int *index, const binary_tree_t *tree,
void (*func)(int *, int, int *))
{
	if (tree == NULL || func == NULL)
		return;

	func(array, tree->n, index);
	tree_preorder(array, index, tree->left, func);
	tree_preorder(array, index, tree->right, func);
}
/**
 * populate_array - populates an array with the values of a binary tree
 * @array: to store values of nodes
 * @n: value of the node
 * @index: pointer to index
*/
void populate_array(int *array, int n, int *index)
{
	array[(*index)++] = n;
}
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
		return (-2147483648);

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
		return (2147483647);

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
	int left_max, right_min, l_sub, r_sub, root, *array = NULL, index = 0;
	size_t i, j, size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	if (size == 1)
		return (1);
	array = malloc(sizeof(int) * size);
	tree_preorder(array, &index, tree, populate_array);
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (0);
			}
		}
	}
	free(array);
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
	l_sub = tree->left ? binary_tree_is_bst(tree->left) : 1;
	r_sub = tree->right ? binary_tree_is_bst(tree->right) : 1;
	return (l_sub && r_sub);
}
