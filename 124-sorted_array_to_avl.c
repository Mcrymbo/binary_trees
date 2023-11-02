#include "binary_trees.h"

/**
 * avl_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void avl_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		avl_tree(&((*node)->left), array, mid, 1);
		avl_tree(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		avl_tree(&((*node)->right), array, mid, 1);
		avl_tree(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - creates new root node
 * and calls to avl_tree
 *
 * @array: input array of integers
 * @size: array size
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	avl_tree(&root, array, middle, 1);
	avl_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}
