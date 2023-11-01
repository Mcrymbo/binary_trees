#include "binary_trees.h"

/**
 * binary_tree_size - measures the number of nodes
 * @tree: pointer to root node
 * Return: size of tree, or 0 if null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}

