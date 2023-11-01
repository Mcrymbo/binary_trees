#include "binary_trees.h"

/**
 * bst_insert_recussive - insert a value in BST recussively
 * @tree: double pointer to root node
 * @value: value to insert to the node
 * Return: pointer to node inserted
 */
bst_t *bst_insert_recussive(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
			return (bst_insert_recussive(&((*tree)->left), value));
	}
	if (value > (*tree)->n)
	{
		if (!((*tree)->right))
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
			return (bst_insert_recussive(&((*tree)->right), value));
	}
	return (NULL);
}

/**
 * bst_insert - inserts avalue in BST
 * @tree: double pointer to root pointer
 * @value: store value to insert the node
 * Return: pointer to created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (bst_insert_recussive(tree, value));
}
