#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - inserts value
 * @root: is a pointer to the parent node of the node to create.
 * @value: the value of the new node
 * Return: return a pointer to the new node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	node = malloc(sizeof(heap_t));
	if (node == NULL)
	{
		return (NULL);
	}

	node->parent = *root;
	node->n = value;
	node->right = NULL;
	node->left = NULL;
	return (node);
}
