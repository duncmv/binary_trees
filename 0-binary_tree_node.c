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
