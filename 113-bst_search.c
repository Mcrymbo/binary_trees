#include "binary_trees.h"

/**
 * bst_search - searches a value in BST
 * @tree: pointer to root node of BST to search
 * @value: value to search in the tree
 * Return: pointer to node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else
		return (NULL);
}
