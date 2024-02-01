#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right rotatation on a binary tree
 * @tree: pointer to the node to rotate
 *
 * Return:pointer to the new root of tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);
	tree->left->parent = tree->parent;
	tree->parent->right = tree->left;
	tree->parent = tree->left;
	tree->left = tree->parent->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent->right = tree;

	return (tree->parent);
}
