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
 * level_order_recussive - implements level order
 * recussively
 * @tree: pointer to root node
 * @level: level of the tree
 * @func: pointer to function to call to each node
 * Return: no return
 */
void level_order_recussive(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		level_order_recussive(tree->left, level - 1, func);
		level_order_recussive(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - level order traversal
 * @tree: pointer to root node
 * @func: pointer to function to call for each node
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 0, height = binary_tree_height(tree);

	if (!tree || !func)
		return;
	for (; level <= height; level++)
	{
		level_order_recussive(tree, level, func);
	}
}
