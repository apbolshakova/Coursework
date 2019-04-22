#include "Header.h"

int main(void)
{
	node_t* root = getFileSystem();
	handleMainCycle(root); //handle main cycle while not exit
	flushFileSystem(root); //flush
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

void handleMainCycle(node_t* root)
{
	node_t* curNode = root; //папка или файл, в котором находимся
	operation_code_t operationCode = NULL_OPERATION;
	do
	{
		system("cls");
		printPathToNode(curNode);
		if (curNode->data) printTextFile(curNode);
		else printFolder(curNode);
		scanf("%c", &operationCode);
		switch (operationCode)
		{
		//операции: подняться на уровень выше, сохранить текущее дерево в файл
		  //папка => создать папку/файл, удалить папку/файл, переместить папку/файл
		  //файл => редактировать текст
		default: break;
		}
	} while (operationCode != EXIT);
}