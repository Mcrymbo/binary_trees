#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary node
 * @parent: pointer to the parent node
 * @value: value to inser to the data
 * Return: pointer to node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;
	parent = newnode;

	return (newnode);
}

/**
 * get_last_node - determines the node at
 * the last level-order
 * @node: root node
 * Return: the node
 */
heap_t *get_last_node(heap_t *node)
{
	if (!node)
		return (NULL);
	while (node->left || node->right)
	{
		if (node->right)
			node = node->right;
		else
			node = node->left;
	}
	return (node);
}

/**
 * heapfy_down - maintaining max Heap property
 * @root: root node
 * Return: no return
 */
void heapfy_down(heap_t *root)
{
	heap_t *max;
	int temp;

	if (!root)
		return;
	max = root;
	if (root->left && root->left->n > max->n)
		max = root->left;
	if (root->right && root->right->n > max->n)
		max = root->right;
	if (max != root)
	{
		temp = max->n;
		max->n = root->n;
		root->n = temp;
		heapfy_down(max);
	}
}

/**
 * heap_extract - extract the root node
 * @root: double pointer to root node
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node_l;

	if (!root || !(*root))
		return (0);
	value = (*root)->n;
	node_l = get_last_node(*root);
	if (*root == node_l)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	if (node_l->parent->left == node_l)
		node_l->parent->left = NULL;
	else
		node_l->parent->right = NULL;
	node_l->parent = NULL;
	node_l->left = (*root)->left;
	node_l->right = (*root)->right;

	if ((*root)->left)
		(*root)->left->parent = node_l;
	if((*root)->right)
		(*root)->right->parent = node_l;
	free(*root);
	*root = node_l;
	heapfy_down(*root);
	return (value);
}
