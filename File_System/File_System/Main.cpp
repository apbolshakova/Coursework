#include "Header.h"

int main(void)
{
	node_t* root = getFileSystem();
	//handle main cycle while not exit
	//flush
}

node_t* getFileSystem()
{
	unsigned int operationCode = 0;
	printf("Enter:\n");
	printf("1 - to create new file system\n");
	printf("2 - to open existing file system\n");
	scanf("%c", &operationCode);
	switch (operationCode)
	{
	case 1: return createFileSystem(); break;
	case 2: return loadFileSystem(); break;
	default: break;
	}
}