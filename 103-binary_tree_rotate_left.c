#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left rotatation on a binary tree
 * @tree: pointer to the node to rotate
 *
 * Return:pointer to the new root of tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (tree);
	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->parent->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent->left = tree;

	return (tree->parent);
}
