#include "binary_trees.h"

/**
 * array_to_heap - builds heap tree from array
 * @array: array of integers
 * @size: size of the array
 * Return: pointer to root node of created binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	heap_t *tree = NULL;

	for (; i < size; i++)
		heap_insert(&tree, array[i]);
	return (tree);
}
