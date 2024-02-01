#include "binary_trees.h"
#include "limits.h"
static size_t leafs_align_(const binary_tree_t *tree, size_t *dpth);
static int partial_complete(const binary_tree_t *tree);
static int is_full(const binary_tree_t *tree);

/**
 * partial_complete - Internal nodes can have 0, 1, or 2 children
 * @tree: pointer to a binary tree
 *
 * Return: 0 for false and 1 for true
 */
static int partial_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left)
	{
		if (tree->right == NULL && tree->left->left)
			return (0);
		if (tree->right == NULL && tree->left->right)
			return (0);
		/* return (1); */
	}
	else if (tree->right && tree->left == NULL)
		return (0);

	return (partial_complete(tree->left) && partial_complete(tree->right));
}

static int is_full(const binary_tree_t *tree)
{
	/**
	 * A binary tree is full if each node has extacly 0 or two children.
	 * There is no node with only left or right child.
	 * They either have both or none at all
	 */
	if (tree == NULL)
		return (1);

	if (tree->left && tree->right == NULL)
		return (0);
	else if (tree->right && tree->left == NULL)
		return (0);

	return (is_full(tree->left) && is_full(tree->right));
}

/**
 * leafs_align - checks if leafs level align
 * @tree: pointer to a binary tree
 * @leaf_depth: pointer to keep track of leaf_depth accross invoctions
 *
 * Return: 1 for true and 0 for false
 */
static size_t leafs_align_(const binary_tree_t *tree, size_t *leaf_depth)
{
	size_t current_depth;
	const binary_tree_t *tmp;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{
		for (current_depth = 0, tmp = tree; tmp; tmp = tmp->parent)
			current_depth++; /* gets the depth of current node */

		if (*leaf_depth == 0)
			*leaf_depth = current_depth;
		if (*leaf_depth != current_depth)
		{
			printf("leaf_depth: %lu, curr_depth: %lu\n", *leaf_depth, current_depth);
			return (0); /* Early return */
		}
	}
	return leafs_align_(tree->left, leaf_depth) &&
		       leafs_align_(tree->right, leaf_depth)
		   ? 1
		   : 0;
}

size_t leaf_depth = INT_MAX;

size_t leafs_align(const binary_tree_t *tree)
{
	const binary_tree_t *tmp;
	size_t current_depth;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
	{
		for (current_depth = -1, tmp = tree; tmp; tmp = tmp->parent)
			current_depth++; /* gets the depth of current node */

		if (leaf_depth == INT_MAX)
			leaf_depth = current_depth;
		if (leaf_depth != current_depth)
		{
			printf("\nleaf_depth: %lu, curr_depth: %lu-:\t", leaf_depth, current_depth);
			return (0);
		}
	}

	return (leafs_align(tree->left) && leafs_align(tree->right)) ? 1 : 0;
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 for true and 0 for false
 * A complete Binary Tree:
 * 1. All the leafs must be on the same level
 * 2. Internal nodes can have 0, 1, or 2 children
 *
 * HOW
 * If a node is leaf, get its depth.
 * No two leafs can have different depths
 * Ensure the height is logarithmic with the number of nodes
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* size_t leaf_depth = 0; */

	(void)partial_complete;
	(void)leafs_align_;

	/* if (!leafs_align(tree, &leaf_depth)) */
	if (!leafs_align(tree))
		return (0);

	if (!is_full(tree))
		return (0); /* All leafs aren't on the same level */
	return (1);
}
