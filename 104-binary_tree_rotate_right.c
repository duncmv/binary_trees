#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right rotatation on a binary tree
 * @tree: pointer to the node to rotate
 *
 * Return:pointer to the new root of tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root = tree;

	if (tree == NULL)
		return (NULL);

	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->left->right;
	tree->parent->right = tree;

	while (root)
	{
		if (root->parent == NULL)
			break;
		root = root->parent;
	}
	return (root);
}
