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
	if (printDir() == FAIL)
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

status_t printDir()
{
	path_t* path = NULL;
	if (getPath(&path) == FAIL)
	{
		deletePath(&path);
		printf("ERROR: unable to get path.\n");
		return FAIL;
	}
	if (printPath(path) == FAIL)
	{
		deletePath(&path);
		printf("ERROR: unable to print path.\n");
		return FAIL;
	}
	printf("\n");
	deletePath(&path);
	return SUCCESS;
}

status_t printContents()
{
	if (cur->type == 'T') printText(cur->data);
	for (int i = 0; i < cur->childrenNum; i++)
	{
		printf("%i. %s", i, cur->child[i]->name);
		if (cur->child[i]->type == 'T') printf(".txt");
		printf("\n");
	}
	printf("\n");
	return SUCCESS;
}

void printText(char* text)
{
	while (*text)
	{
		printf("%c", *text);
		text++;
	}
	printf("\n");
}

void printMainMenu()
{
	printf("Press key depend on what would you like to do:\n");
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

actionID_t getID() //TODO test
{
	actionID_t action = invalidID;
	char* mask = NULL;
	if (cur->type == 'F') mask = FOLDER_MASK;
	else if (cur->type == 'T') mask = FILE_MASK;
	else return action;
	fflush(stdin);
	do {
		action = _getch();
	} while (!strchr(mask, action));
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