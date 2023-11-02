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

/**
 * node_swap - swaps nodes when child node is
 * greater than parent
 * @node_p: pointer to parent node
 * @node_c: pointer to child node
 */
void node_swap(heap_t **node_p, heap_t **node_c)
{
	int lr;
	heap_t *node, *child, *child_node, *left_node, *right_node, *parent;

	node = *node_p,	child = *node_c;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			child_node = node->right, lr = 0;
		else
			child_node = node->left, lr = 1;
		left_node = child->left, right_node = child->right;
		if (lr == 0)
		{
			child->right = child_node;
			if (child_node)
				child_node->parent = child;
			child->left = node;
		}
		else
		{
			child->left = child_node;
			if (child_node)
				child_node->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent, node->parent = child;
		node->left = left_node,	node->right = right_node, *node_p = child;
	}
}

/**
 * heap_insert - inserts a value in max binary heap
 * @root: pointer to root node
 * @value: value to insert
 * Return: pointer created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newnode;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			newnode = heap_insert(&((*root)->left), value);
			node_swap(root, &((*root)->left));
			return (newnode);
		}
		else
		{
			newnode = (*root)->left = binary_tree_node(*root, value);
			node_swap(root, &((*root)->left));
			return (newnode);
		}
	}
	if ((*root)->right)
	{
		newnode = heap_insert(&((*root)->right), value);
		node_swap(root, &((*root)->right));
		return (newnode);
	}
	else
	{
		newnode = (*root)->right = binary_tree_node(*root, value);
		node_swap(root, &((*root)->right));
		return (newnode);
	}
	return (NULL);
}
