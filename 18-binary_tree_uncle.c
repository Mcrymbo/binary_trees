#include "binary_trees.h"

/**
 * binary_tree_uncle - finds uncle of a node
 * @node: pointer to node to find the uncle
 * Return: pointer to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);
	else
		return (NULL);
}
