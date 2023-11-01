#include "binary_trees.h"

/**
 * bst_recussive - to check if a tree is a valid BST
 * recussively
 * @tree: pointer to root node of the tree
 * @min: minimum integer
 * @max: maximum
 * Return: 1 if tree is BST, 0 otherwise
 */
int bst_recussive(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (bst_recussive(tree->left, min, tree->n) &&
			bst_recussive(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if tree is BST
 * @tree: pointer to root node of a tree
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_recussive(tree, INT_MIN, INT_MAX));
}
