#include "binary_trees.h"

/**
 * binary_tree_delete - deletes and entire binary tree
 * @tree: pointer to the tree to delete
 * Return: no return
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
