#include "binary_trees.h"

/**
 * binary_tree_size - measures the number of nodes
 * @tree: pointer to root node
 * Return: size of tree, or 0 if null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
        if (!tree)
                return (0);
        return (binary_tree_size(tree->left) +
                        binary_tree_size(tree->right) + 1);
}

/**
 * heap_to_sorted_array - converts
 * binary max heap to sorted array
 * @heap: pointer to root node
 * @size: size of array
 * Return: pointer to sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, size_h;

	if (!heap || !size)
		return (NULL);

	size_h = binary_tree_size(heap);
	array = malloc(sizeof(int) * size_h);
	if (!array)
		return (NULL);
	for (i = 0; i < size_h; i++)
	{
		array[i] = heap->n;
		heap_extract(&heap);
	}
	*size = size_h;
	return (array);
}
