#include "Common.h"
#include "Types.h"

status_t createNode()
{
    create_type enterType = invalidTC;
	fflush(stdin);
	do 
    {
		system("cls");
		printf("Please enter which type of file you want to create:\n");
		printf("F - create new folder\n");
		printf("T - create new text file\n");
		enterType = _getch();
	} while (!strchr(TYPE_MASK, enterType));
	system("cls");
	char* newName = NULL;
	newName = getFileName();
	system("cls");
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (!newNode)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	newNode->name = newName;
	newNode->type = enterType;
	newNode->parent = cur;
	if (newNode->type == 'F') newNode->childrenNum = 0;
	else newNode->childrenNum = INVALID;
	newNode->child = NULL;
	newNode->data = NULL;

	cur->childrenNum++;
	node_t* valuesChildren = (node_t*)realloc(cur->child, sizeof(node_t)*cur->childrenNum);
	if (!valuesChildren)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	cur->child = valuesChildren;
	cur->child[cur->childrenNum - 1] = newNode;
	return SUCCESS;
}

void deleteChildrenRecur(node_t* curRecur)
{
	int iChild = 0;
	if (curRecur->child)
	{
		for (iChild = 0; iChild < curRecur->childrenNum; iChild++)
		{
			if (curRecur->child[iChild])  //рекурсивное удаление детей curRecur
				deleteChildrenRecur(curRecur->child[iChild]);
		}
	}
	free(curRecur->name);
	curRecur->name = NULL;
	if (curRecur->data)
	{
		free(curRecur->data);
		curRecur->data = NULL;
	}
	free(curRecur);
	curRecur = NULL;
}

status_t deleteNode()
{
	int childID = getChildIDforDeleting();
	if (cur->childrenNum <= childID || childID < 0)
	{
		printf("ERROR: attempt to delete not existing file.\n");
		return FAIL;
	}
	if (cur->child[childID])
		deleteChildrenRecur(cur->child[childID]);
	int iDelete = 0;
	for (iDelete = childID; iDelete < (cur->childrenNum-1); iDelete++)
	{
		cur->child[iDelete] = cur->child[iDelete+1];
	}
	cur->child[cur->childrenNum] = '\0';
	cur->childrenNum--;
	return SUCCESS;
}

int getChildID()
{
	int childID = 0;
	printf("Print ID of file which you want to open: ");
	scanf("%i", &childID);
	return childID;
}

int getChildIDforDeleting()
{
	int childID = 0;
	printf("Print ID of file which you want to delete: ");
	scanf("%i", &childID);
	return childID;
}

status_t renameNode()
{
	int childID = getChildID();
	if (cur->childrenNum <= childID || childID < 0)
	{
		printf("ERROR: attempt to open not existing file.\n");
		return FAIL;
	}
	
	char* changingName =NULL;
	changingName = getFileName();
	cur->child[childID]->name = changingName;
	return SUCCESS;
}

status_t openNode()
{
	int childID = getChildID();
	if (cur->childrenNum <= childID || childID < 0)
	{
		printf("ERROR: attempt to open not existing file.\n");
		return FAIL;
	}
	cur = cur->child[childID];
	return SUCCESS;
}

status_t closeNode()
{
	if (!cur->parent)
	{
		printf("ERROR: attempt to close root.\n");
		return FAIL;
	}
	cur = cur->parent;
	return SUCCESS;
}

status_t searchNode()
{
	int iSearch = 0;
	char* searchName = NULL;
	searchName = getFileName();
	int findingName = 0;
	if (cur->child)
	{
		for (iSearch = 0; iSearch < cur->childrenNum; iSearch++)
			searchChildrenRecur(cur->child[iSearch], searchName, &findingName);
		if (findingName == 0)
			printf("The file or the folder with such name is not found.\n");
	}
	else
		printf("The file or the folder with such name is not found.\n");
	return SUCCESS;
}

void searchChildrenRecur(node_t* curRecur, char* searchName, int* findingName)
{
	int iSearch = 0;
	if (curRecur->child)
	{
		for (iSearch = 0; iSearch < curRecur->childrenNum; iSearch++)
		{
			if (curRecur->child[iSearch])  //рекурсивный поиск детей curRecur
				searchChildrenRecur(curRecur->child[iSearch], searchName, &findingName);
		}
	}
	if (strcmp(curRecur->name, searchName) == 0)
	{
		findingName = 1;
		printNodeInfo(curRecur);
	}
	}

void printNodeInfo(node_t* curRecur)
{
	printDir(node_t* curRecur);
	if (curRecur->type == 'T')
	{
		int dataSize = 0;
		dataSize = strlen(curRecur->data);
		printf("Size of data of this text file is %i symbols.\n", dataSize);
	}
	else if (curRecur->type == 'F')
	{
		int dataSize = 0;
		dataSize = curRecur->childrenNum;
		printf("Number of children of this folder is %i.\n", dataSize);
	} 
}
