#include "binary_trees.h"

/**
 * node_is_leaf - checks if node is leaf
 * @node: pointer to the node to check
 * Return: 1 if leaf, 0 otherwise
 */
int node_is_leaf(const binary_tree_t *node)
{
	if (node && !(node->left) && !(node->right))
		return (1);
	else
		return (0);
}

/**
 * parent_node_is_full - checks if parent node is full
 * @node: pointer to node to check
 * Return: 1 if full, 0 otherwise
 */
int parent_node_is_full(const binary_tree_t *node)
{
	if (node && node->left && node->right)
		return (1);
	else
		return (0);
}

/**
 * height - determines the height
 * of binary tree
 * @tree: pointer to root node of binary tree to traverse
 * Return: height of the tree or 0 for null
 */
int height(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0;

	if (!tree)
		return (-1);
	height_left = height(tree->left);
	height_right = height(tree->right);

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary
 * tree is perfect
 * @tree: pointer to root node
 * Return: 1 if perfect and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);
		if (node_is_leaf(tree->left) &&
				node_is_leaf(tree->right))
			return (1);
		if (parent_node_is_full(tree))
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}
	return (0);
}
