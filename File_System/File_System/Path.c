#include "Common.h"

status_t getPath(path_t** path, node_t* file)
{
	node_t* node = cur;
	if (file) node = file;
	while (node)
	{
		if (pushIntoPath(path, node) == FAIL)
		{
			printf("ERROR: unable to add node into path.\n");
			return FAIL;
		}
		node = node->parent;
	}
	return SUCCESS;
}

status_t pushIntoPath(path_t** root, node_t* node)
{
	path_t* newEl = (path_t*)malloc(sizeof(path_t));
	if (!newEl)
	{
		printf("ERROR: memory allocation error.\n");
		return FAIL;
	}
	newEl->node = node;
	if (!(*root)) newEl->next = NULL;
	else newEl->next = *root;
	*root = newEl;
	return SUCCESS;
}

status_t printPath(path_t* root)
{
	if (!root)
	{
		printf("ERROR: path begin is not defined.\n");
		return FAIL;
	}
	path_t* el = root;
	while (el)
	{
		printf("%s", el->node->name);
		if (el->node->type == 'F') printf("/");
		else if (el->node->type == 'T') printf(".txt");
		el = el->next;
	}
	printf("\n");
	return SUCCESS;
}

void deletePath(path_t** root)
{
	path_t* temp = *root;
	while (*root)
	{
		*root = (*root)->next;
		free(temp);
		temp = NULL;
		temp = *root;
	}
}