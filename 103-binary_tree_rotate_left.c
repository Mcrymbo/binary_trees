#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left
 * rotation of the binary tree
 * @tree: root node of the tree
 * Return: pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !(tree->right))
		return (tree);
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	new_root->parent = tree->parent;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
