#include "Common.h"
node_t* root = NULL;
node_t* cur = NULL;

int main(void)
{
	if (getFS() == FAIL)
	{
		printf("ERROR: unable to get file system.\n");
		cleanup();
		return 0;
	}
	handleMainCycle();
	flushFS(); 
	deleteFS();
	return 0;
}

void handleMainCycle()
{
	cur = root;
	actionID_t action = invalidID;
	do
	{
		system("cls");
		if (printCurNode() == FAIL)
		{
			printf("ERROR: file system data is corrupted.\n");
			break;
		}
		printMainMenu();
		action = getID();
		if (handleAction(action) == FAIL) printf("\nAction wasn't completed.\n");
		printf("Press any button to continue.\n");
		_getch();
	} while (action != exitID);
}

status_t printCurNode()
{
	if (printPath() == FAIL)
	{
		print("ERROR: unable to print path to currect directory.\n");
		return FAIL;
	}
	if (printContents() == FAIL)
	{
		print("ERROR: unable to print contents of the current directory.\n");
		return FAIL;
	}
	return SUCCESS;
}

status_t printPath()
{
	//TODO
	return SUCCESS;
}

status_t printContents()
{
	//TODO
	return SUCCESS;
}

void printMainMenu()
{
	//TODO
}

actionID_t getID()
{
	actionID_t action = invalidID;
	//read from input
	return action;
}

status_t handleAction(actionID_t action)
{
	system("cls");
	printCurNode();
	if (!root || !cur)
	{
		printf("ERROR: file system is not defined.\n");
		return FAIL;
	}
	switch (action)
	{
	case flushID: return flushFS(); break;
	case createID: return createNode(); break;
	case deleteID: return deleteNode(); break;
	case renameID: return renameNode(); break;
	case openID: return handleOpening(); break;
	case closeID: return handleClosing(); break;
	case editID: return editFile(); break;
	case exitID: return SUCCESS;
	}
	printf("ERROR: Invalid action.\n");
	return FAIL;
}