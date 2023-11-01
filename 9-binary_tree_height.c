#include "binary_trees.h"

/**
 * tree_height - determines the height
 * of binary tree
 * @tree: pointer to root node of binary tree to traverse
 * Return: height of the tree or 0 for null
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);
	height_left = tree_height(tree->left);
	height_right = tree_height(tree->right);

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_height - returns tree height
 * @tree: pointer to root node
 * Return: tree height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_height(tree) - 1);
}
