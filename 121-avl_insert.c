#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as a right-child of another node
 * @current: pointer to node to insert right-child
 * @value: value to store in new node
 * Return: pointer to new node or NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *current, int value)
{
	binary_tree_t *node = NULL;

	if (current == NULL)
		return (NULL);
	node = binary_tree_node(current, value);
	if (node == NULL)
		return (NULL);

	if (current->right != NULL)
	{
		current->right->parent = node;
		node->right = current->right;
	}
	current->right = node;

	return (node);
}
/**
 * binary_tree_insert_left - inserts a node as a left-child of another node
 * @current: pointer to node to insert left-child
 * @value: value to store in new node
 * Return: pointer to new node or NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *current, int value)
{
	binary_tree_t *node = NULL;

	if (current == NULL)
		return (NULL);
	node = binary_tree_node(current, value);
	if (node == NULL)
		return (NULL);

	if (current->left != NULL)
	{
		current->left->parent = node;
		node->left = current->left;
	}
	current->left = node;

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
/**
 * avl_rotation - carries our AVL rotations for LL, LR, RR and RL cases
 * @node: current node
*/
void avl_rotation(avl_t *node)
{
	avl_t *current = node, *child;
	int balance, balance_child;

	while (current != NULL && current->parent != NULL)
	{
		balance = binary_tree_balance(current);
		if (balance > 1)
		{
			child = current->left;
			balance_child = binary_tree_balance(child);
			if (balance_child > 0)
			{
				binary_tree_rotate_right(child);
				break;
			}
			else if (balance_child < 0)
			{
				binary_tree_rotate_left(child);
				binary_tree_rotate_right(current);
				break;
			}
		}
		else if (balance < -1)
		{
			child = current->right;
			balance_child = binary_tree_balance(child);
			if (balance_child < 0)
			{
				binary_tree_rotate_left(current);
				break;
			}
			else if (balance_child > 0)
			{
				binary_tree_rotate_right(child);
				binary_tree_rotate_left(current);
				break;
			}
		}
		current = current->parent;
	}
}
/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: double bointer to the root node of the AVL tree
 * @value: value to store in node
 * Return: pointer to node or NULL
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *current;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = bst_insert(tree, value);
	current = node;
	avl_rotation(current);

	return (node);
}
