#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create.
 * @value: the value of the new node
 * Return: return a pointer to the new node, or NULL on failure
*/


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
	{
		return (NULL);
	}

	node->parent = parent;
	node->n = value;
	node->right = NULL;
	node->left = NULL;
	return (node);
}
