#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right rotatation on a binary tree
 * @tree: pointer to the node to rotate
 *
 * Return:pointer to the new root of tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right != NULL)
		new_root->right->parent = tree;

	new_root->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	tree->parent = new_root;
	new_root->right = tree;

	return (new_root);
}
