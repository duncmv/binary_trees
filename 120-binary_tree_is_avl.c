#include "binary_trees.h"
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
 * bst_lesser - BST validator helper function lesser
 * @node: node to compare
 * @val: value to compare with
 * Return: 1 if valid BST, else 0
 */
int bst_lesser(const binary_tree_t *node, int val)
{
	if (node == NULL)
		return (1);
	if (node->n >= val)
		return (0);

	return (bst_lesser(node->left, val) &&
		bst_lesser(node->right, val));
}

/**
 * bst_greater - BST validator helper function greater
 * @node: node to compare
 * @val: value to compare with
 * Return: 1 if valid BST, else 0
 */
int bst_greater(const binary_tree_t *node, int val)
{
	if (node == NULL)
		return (1);
	if (node->n <= val)
		return (0);

	return (bst_greater(node->left, val) &&
		bst_greater(node->right, val));
}
/**
 * tree_is_bst - Check if a binary tree is a valid binary search tree
 * @tree: pointer to root node of tree to check
 * Return: 1 if valid BST, else 0
 */
int tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_lesser(tree->left, tree->n) &&
		bst_greater(tree->right, tree->n));
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of tree to check
 * Return: 1 if tree is valid AVL tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int diff, left, right, bst;

	if (tree == NULL)
		return (0);

	diff = tree_height(tree->left) - tree_height(tree->right);
	bst = tree_is_bst(tree);
	if (tree->left == NULL || tree->right == NULL)
	{
		if (diff != 0)
			return (0);
	}

	if (diff <= 1 && diff >= -1 && bst)
	{
		left = tree->left ? binary_tree_is_avl(tree->left) : 1;
		right = tree->right ? binary_tree_is_avl(tree->right) : 1;
		if (left == 1 && right == 1)
			return (1);
	}

	return (0);
}
