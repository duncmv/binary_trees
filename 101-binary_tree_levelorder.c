#include "binary_trees.h"

#define MAX_Q_SIZE 500 /*assuming we have no more than 500 nodes*/

/**
 * createQueue - creates a queue that will store nodes
 * @front: pointer to front
 * @rear: pointer to rear
 *
 * Return: the queue
*/
binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **queue = (binary_tree_t **)malloc(
		sizeof(binary_tree_t *) * MAX_Q_SIZE);

	*front = *rear = 0;
	return (queue);
}
/**
 * enQueue - places the node in a queue
 * @queue: the queue
 * @rear: rear position of the queue
 * @new_node: node to be added
*/
void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}
/**
 * deQueue - dequeues a node
 * @queue: the queue
 * @front: front position of the queue
 *
 * Return: what was formerly at the front of the queue
*/
binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree
 * @func: pointer to helper function
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int rear, front;
	binary_tree_t **queue = createQueue(&front, &rear);
	binary_tree_t *temp_node = (binary_tree_t *)tree;

	while (temp_node)
	{
		func(temp_node->n);

		/*Enqueue left child*/
		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		/* Enqueue right child*/
		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		/* Dequeue node and make it temp_node*/
		temp_node = deQueue(queue, &front);
	}
	free(queue);
}
