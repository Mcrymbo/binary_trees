#include "binary_trees.h"

/**
 * tree_balance - checks and balances each node of the tree
 * @node: pointer to the node to balance
 * @value: value in the node
 */
void tree_balance(avl_t **node, int value)
{
	int bal = binary_tree_balance(*node);

	if (bal > 1 && value < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}
	if (bal < -1 && value > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}
	if (bal > 1 && value > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}
	if (bal < -1 && value < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * check_avl - check if a node is inserted into avl
 * @tree: pointer to root node
 * @value: value in the node
 * Return: pointer to new node
 */
avl_t *check_avl(avl_t **tree, int value)
{
	avl_t *node;

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			node = check_avl(&((*tree)->left), value);
			if (node)
				tree_balance(tree, value);
			return (node);
		}
	}
	if ( value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			node = check_avl(&((*tree)->right), value);
			if (node)
				tree_balance(tree, value);
			return (node);
		}
	}
	return (NULL);
}

/**
 * avl+insert - inserts a value into AVL tree
 * @tree: pointer to root node of the AVL tree
 * @value: value to insert into the tree
 * Return: pointer to the created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node = check_avl(tree, value);
	return (node);
}
