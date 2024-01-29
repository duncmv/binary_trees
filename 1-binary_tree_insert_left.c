#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as a left-child of another node
 * @parent: pointer to node to insert left-child
 * @value: value to store in new node
 * Return: pointer to new node or NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = node;
		node->left = parent->left;
	}
	parent->left = node;

	return (node);
}
