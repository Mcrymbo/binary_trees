#include "binary_trees.h"

/**
 * binary_tree_sibling - finds a sibleng of a node
 * @node: node to find its sibling
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}
