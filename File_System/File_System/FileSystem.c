#include "Header.h"

node_t* createFileSystem()
{
	node_t* root = (node_t*)malloc(sizeof(node_t));
	root->name = ROOT_NAME;
	root->parent = NULL;
	root->childrenNum = 0;
	root->child = NULL;
	root->data = NULL;
	return root;
}

node_t* loadFileSystem()
{
	//очистить экран
	printf("Enter name of file or press ESC to return: ");
	//load file
	//build tree and return head of it
	return NULL;
}