#include "binary_trees.h"

/**
 * array_to_avl - builds avl from array
 * @array: pointer to first element of array
 * @size: size of array
 * Return: pointer to root node
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
	if (i == size)
		return (tree);
	return (NULL);
}
