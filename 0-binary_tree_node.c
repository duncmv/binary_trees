#include "binary_trees.h"
/**
 * binary_tree_node - creates a node for a binary tree
 * @parent: pointer to parent node
 * @value: value to put in the new node
 * Return: pointer to a new node or NULL
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
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