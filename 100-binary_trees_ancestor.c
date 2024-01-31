#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	/**
	 * for each parent of first starting with itself, loop through second's
	 * parents to find a possible common parent. This will get the closest
	 * common ancestor since for each ancestor a level up, a check is done
	 * for all of second's parents.
	 */
	const binary_tree_t *ancestor, *fst, *sec;

	ancestor = NULL;
	for (fst = first; fst && ancestor == NULL; fst = fst->parent)
		for (sec = second; sec && ancestor == NULL; sec = sec->parent)
			if (fst->n == sec->n)
				ancestor = fst;
	return ((binary_tree_t *)ancestor);
}
