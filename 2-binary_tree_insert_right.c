#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as a right-child of another node
 * @parent: pointer to node to insert right-child
 * @value: value to store in new node
 * Return: pointer to new node or NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		parent->right->parent = node;
		node->right = parent->right;
	}
	parent->right = node;

	return (node);
}
