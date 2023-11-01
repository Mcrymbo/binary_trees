#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a binary tree is a root
 * @node: pointer to a node to check if is a root
 * Return: 1 if the node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	else
		return (0);
}
