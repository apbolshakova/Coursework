#include "Common.h"

status_t getFS()
{
	actionID_t action = invalidID;
	fflush(stdin);
	do {
		system("cls");
		printf("Type how to start:\n");
		printf("i - create new file system\n");
		printf("l - load existing file system");
		action = _getch();
	} while (!strchr(FS_MASK, action));
	switch (action)
	{
	case initID: return initFS(); break;
	case loadID: return loadFS();
	}
}

status_t initFS()
{
	return SUCCESS;
}

status_t loadFS()
{
	return SUCCESS;
}

status_t flushFS()
{
	return SUCCESS;
}

status_t deleteFS()
{
	return SUCCESS;
}

//TODO: reuse and cleanup
/*node_t* createFileSystem()
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
}*/