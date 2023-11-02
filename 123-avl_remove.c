#include "binary_trees.h"

/**
 * tree_balance_avl - checks and balances each node of the tree
 * @node: pointer to the node to balance
 * @value: value in the node
 */
void tree_balance_avl(avl_t **node, int value)
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
 * inorder_successor - used to determine previous/next node
 * of the removed node
 * @tree: pointer to root node
 * @mode: 1 for successor, 2 for predecessor
 * Return: pointer to predecessor/succcessor node
 */
avl_t *inorder_successor(avl_t *tree, int mode)
{
	avl_t *node;

	if (mode == 1)
	{
		if (!tree->left)
		{
			if (tree == tree->parent->left)
				tree->parent->left = NULL;
			else
				tree->parent->right = NULL;
			return (tree);
		}
		node = inorder_successor(tree->left, 1);
	}
	else
	{
		if (!tree->right)
		{
			if (tree == tree->parent->right)
				tree->parent->right = NULL;
			else
				tree->parent->left = NULL;
			return (tree);
		}
		node = inorder_successor(tree->right, 2);
	}
	return (node);
}

/**
 * change_node - changes the node removed by
 * the previous/next
 * @node_r: pointer to removes node
 * @node_s: pointer to predecessor/succsessor node
 */
void change_node(avl_t **node_r, avl_t **node_s)
{
	if ((*node_r)->left && (*node_r)->left != (*node_s))
	{
		if ((*node_s)->left)
		{
			(*node_s)->parent->right = (*node_s)->left;
			(*node_s)->left->parent = (*node_s)->parent;
		}
		(*node_s)->left = (*node_r)->left;
		(*node_r)->left->parent = (*node_s);
	}
	if ((*node_r)->right && (*node_r)->right != (*node_s))
	{
		if ((*node_s)->right)
		{
			(*node_s)->parent->left = (*node_s)->right;
			(*node_s)->right->parent = (*node_s)->parent;
		}
		(*node_s)->right = (*node_r)->right;
		(*node_r)->right->parent = (*node_s);
	}
	(*node_s)->parent = (*node_r)->parent;
	if ((*node_r)->parent)
	{
		if ((*node_r)->parent->left == *node_r)
			(*node_r)->parent->left = *node_s;
		else
			(*node_r)->parent->right = *node_s;
	}
}

/**
 * avl_remove_s - searches and removes a node from AVL tree
 * @tree: pointer to root node
 * @value: value in the node to be removes
 * Return: pointer to node removes
 */
avl_t *avl_remove_s(avl_t **tree, int value)
{
	avl_t *node;

	if (tree && *tree && value < (*tree)->n)
	{
		node = avl_remove_s(&((*tree)->right), value);
		tree_balance_avl(tree, value);
		return (node);
	}
	if (tree && *tree)
	{
		if ((*tree)->left || (*tree)->right)
		{
			if ((*tree)->right)
				node = inorder_successor((*tree)->right, 1);
			else
				node = inorder_successor((*tree)->left, 2);
			change_node(tree, &node);
			free(*tree);
			*tree = node;
		}
		else
		{
			node = *tree;
			if ((*tree)->parent)
			{
				if ((*tree)->parent->left == (*tree))
					(*tree)->parent->left = NULL;
				else
					(*tree)->parent->right = NULL;
			}
			free(node);
			*tree = NULL;
		}
	}
	return (*tree);
}

/**
 * avl_remove - removes a node in avl tree
 * @root: pointer to root node
 * @value: node value
 * Return: pointer to new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);
	avl_remove_s(&root, value);
	return (root);
}
