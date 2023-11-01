#include "binary_trees.h"

/**
 * node_depth - measures the depth of a node recusively
 * @node: node to find its depth
 * Return: depth of node
 */
size_t node_depth(const binary_tree_t *node)
{
	if (!node)
		return (-1);
	return (node_depth(node->parent) + 1);
}

/**
 * binary_node_depth -  calls node_depth function
 * to return the depth
 * @node: node to determine depth of
 * Return: depth of node
 */
size_t binary_node_depth(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (node_depth(node) - 1);
}

/**
 * binary_trees_ancestor - determines the lowest
 * common ancetor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to the lowest common ancester
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (binary_node_depth(first) > binary_node_depth(second))
		return (binary_trees_ancestor(first->parent, second));
	else if (binary_node_depth(first) < binary_node_depth(second))
		return (binary_trees_ancestor(first, second->parent));
	else
		return (binary_trees_ancestor(first->parent, second->parent));
}
