#include "binary_trees.h"

/**
 * array_to_bst - function that builds BST in array
 * @array: array that contains values
 * @size: size of the array
 * Return: pointer to the root node, null on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *new_root;

	new_root = NULL;
	for (i = 0; i < size; i++)
	{
		bst_insert(&new_root, array[i]);
	}
	if (i == size)
		return (new_root);
	return (NULL);
}
