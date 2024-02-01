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
/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node of the BST
 * @value: value to be stored in the node
 *
 * Return: pointer to node or NULL
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *temp = *tree;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	while (temp != NULL)
	{
		if (temp->n == value)
			return (NULL);

		if (value < temp->n)
		{
			if (temp->left == NULL)
			{
				node = binary_tree_insert_left(temp, value);
				return (node);
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right == NULL)
			{
				node = binary_tree_insert_right(temp, value);
				return (node);
			}
			temp = temp->right;
		}
	}

	return (NULL);
}
