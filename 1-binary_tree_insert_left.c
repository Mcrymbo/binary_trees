#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as a left child
 * @parent: pointer to the node to insert the left child
 * @value: value to insert
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (!parent)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	if (parent->left)
	{
		newnode->left = parent->left;
		newnode->left->parent = newnode;
	}
	else
		newnode->left = NULL;

	newnode->right = NULL;
	parent->left = newnode;

	return (newnode);
}
