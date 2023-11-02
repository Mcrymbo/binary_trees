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

/**
 * tree_is_avl - checks if a tree is avl recussively
 * @tree: pointer to root node of the tree
 * Return: 1 if it is a valid AVL tree, 0 otherwise
 */
int tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (binary_tree_height(tree->left) -
			binary_tree_height(tree->right) <= 1)
	{
		if (tree_is_avl(tree->left) &&
				tree_is_avl(tree->right))
		{
			if (binary_tree_is_bst(tree))
				return (1);
		}
	}
	return (0);
}

/**
 * binary_tree_is_avl - checks if the tree is avl by
 * calling the recussive function above
 * @tree: pointer to root node
 * Return: 1 if it is avl
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_is_avl(tree));
}
