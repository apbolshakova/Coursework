#include "Common.h"
node_t* root = NULL;
node_t* cur = NULL;

int main(void)
{
	if (getFS() == FAIL)
	{
		printf("ERROR: unable to get file system.\n");
		deleteFS();
		_getch();
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
		if (!root || !cur)
		{
			printf("ERROR: file system is not defined.\n");
			_getch();
			break;
		}
		if (printCurNode() == FAIL)
		{
			printf("ERROR: file system data is corrupted.\n");
			_getch();
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
		printf("ERROR: unable to print path to currect directory.\n");
		return FAIL;
	}
	if (printContents() == FAIL)
	{
		printf("ERROR: unable to print contents of the current directory.\n");
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
	printf("\nPress key depend on what would you like to do:\n");
	printf("General:\n");
	printf("f - save current state as file\n");
	printf("ESC - close program\n");

	if (cur->type == 'F')
	{
		printf("\nFolder:\n");
		printf("n - create new file in this folder\n");
		printf("d - delete file from this folder\n");
		printf("r - rename file in this folder\n");
		printf("o - open file from this folder\n");

	}
	if (cur->type == 'T')
	{
		printf("\nFile:\n");
		printf("e - edit this file\n");
	}
	printf("c - close this directory\n");
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
	switch (action)
	{
	case flushID: return flushFS(); break;
	case createID: return createNode(); break;
	case deleteID: return deleteNode(); break;
	case renameID: return renameNode(); break;
	case openID: return openNode(); break;
	case closeID: return closeNode(); break;
	case editID: return editFile(); break;
	case exitID: return SUCCESS;
	}
	printf("ERROR: Invalid action.\n");
	return FAIL;
}