#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left rotatation on a binary tree
 * @tree: pointer to the node to rotate
 *
 * Return:pointer to the new root of tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root = tree;

	if (tree == NULL)
		return (NULL);

	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->right->left;
	tree->parent->left = tree;

	while (root)
	{
		if (root->parent == NULL)
			break;
		root = root->parent;
	}
	return (root);
}
