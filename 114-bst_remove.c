#include "binary_trees.h"

/**
 * node_is_leaf - checks if a node is a leaf
 * @node: node to check
 * Return: 1 if node is leaf, 0 otherwise
 */
int node_is_leaf(const binary_tree_t *node)
{
	if (node && !(node->left) && !(node->right))
		return (1);
	else
		return (0);
}

/**
 * bst_search - searches for a value in BST
 * @tree: pointer to root node
 * @value: value of the node
 * Return: pointer to node found
 */
bst_t *bst_search(const binary_tree_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));
	if (tree && value > tree->n)
		return (bst_search(tree->right, value));
	return ((bst_t *)tree);
}

/**
 * node_r - removes node for node->right case
 * @tree: pointer to root node
 * @node: node being deleted
 * Return: pointer to root node
 */
bst_t *node_r(bst_t *tree, bst_t *node)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (tree == node)
		tree = node->right;
	if (node->left)
		node->left->parent = node->right;
	free(node);
	return (tree);
}

/**
 * node_r1 - removes node->right
 * @tree: pointer to root node
 * @node: node to remove
 * Return: pointer to root node
 */
bst_t *node_r1(bst_t *tree, bst_t *node)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (tree == node)
		tree = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (tree);
}

/**
 * bst_remove - removes a node from BST
 * @root: pointer to root node
 * @value: value of node to remove
 * Return: pointer to new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = bst_search(root, value);

	if (node)
	{
		if (node_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = node_r1(root, node);
		else if (node->right)
			root = node_r(root, node);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->left;
			if (root == node)
				root = node->left;
			free(node);
		}
	}
	return (root);
}
