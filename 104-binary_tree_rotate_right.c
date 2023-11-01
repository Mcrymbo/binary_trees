#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right
 * rotation on binary tree
 * @tree: pointer to root node of the tree
 * Return: pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !(tree->left))
		return (tree);
	new_root = tree->left;
	tree->left = new_root->right;
	if (tree->left)
		tree->left->parent = tree;
	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}
