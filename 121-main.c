#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *root;
    avl_t *node;

    root = NULL;
    node = avl_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 97);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 99);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 60);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 180);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 250);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 74);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 5326);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 5);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 4);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 3);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 1);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    return (0);
}