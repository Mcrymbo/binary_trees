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
