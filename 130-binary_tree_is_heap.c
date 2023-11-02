#include "binary_trees.h"

/**
 * tree_size - checks the size of the tree
 * @tree: node of the root node
 * Return: size of tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - check if the
 * tree is complete recussively
 * @tree: pointer to the root node of the tree
 * @index: index of current node
 * @size: tree size
 * Return: 1 if the tree is complet, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (tree_is_complete(tree->left, 2 * index + 1,
				size) && tree_is_complete(
					tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - check if a
 * binary tree is complete
 * @tree: pointer to root node
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = tree_size(tree);
	return (tree_is_complete(tree, 0, size));
}

/**
 * check_parent - check if parent has greater value
 * than child
 * @node: pointer to current node
 * Return: 1 if if parent has greater value
 */
int check_parent(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->n > tree->parent->n)
		return (0);
	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - checks if binary tree is a valid
 * max heap tree
 * @tree: pointer to root node
 * Return: 1 if max heap tree, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);
	return (check_parent(tree->left) && check_parent(tree->right));
}
