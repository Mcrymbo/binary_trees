#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node as the right child
 * @parent: pointer to node to insert right child
 * @value: data to stor in the node
 * Return: newnode
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (!parent)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	if (parent->right)
	{
		newnode->right = parent->right;
		newnode->right->parent = parent->right;
	}
	else
		newnode->right = NULL;
	parent->right = newnode;

	return (newnode);
}
