#include "binary_trees.h"

/**
 * tree_depth - measures the depth of a node
 * @tree: pointer to node to measure
 * Return: depth of the node or 0 if null
 */
size_t tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_depth(tree->parent) + 1);
}

/**
 * binary_tree_depth - depth of a node
 * @tree: pointer to node to be measured
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_depth(tree) - 1);
}
