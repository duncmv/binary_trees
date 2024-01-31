#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree
 * @func: pointer to helper function
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->parent == NULL)
		func(tree->n);

	if (tree->left)
		func(tree->left->n);

	if (tree->right)
		func(tree->right->n);

	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
