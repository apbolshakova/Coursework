#include "Common.h"
#include "Types.h"

status_t createNode()
{
    create_type enterType = invalidTC;
	fflush(stdin);
	do {
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
	newNode->childrenNum = 0;
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
			if (curRecur->child[iChild])//рекурсивное удаление детей curRecur
			{
				deleteChildrenRecur(curRecur->child[iChild]);
				free(cur->child[iChild]->name);
				if  (cur->child[iChild]->data)
				   free(cur->child[iChild]->data);
				free(curRecur->child[iChild]);
				curRecur->child[iChild] = NULL;
			}
		}
		free(curRecur->name);
		free(curRecur->data);
		free(curRecur->child);
		curRecur->child = NULL;
	}
	
}

status_t deleteNode()
{
	int childID = getChildID();
	if (cur->childrenNum <= childID || childID < 0)
	{
		printf("ERROR: attempt to delete not existing file.\n");
		return FAIL;
	}
	if (cur->child[childID])
		deleteChildrenRecur(cur->child[childID]);
	
	return SUCCESS;
}

int getChildID()
{
	int childID = 0;
	printf("Print ID of file which you want to open: ");
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
	/*if (!changingName)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	int iChangingName = 0;
	*printf("Please enter which new name you want to give this item:\n");
	while (!strchr(NAME_MASK, changingName[iChangingName]))
	{
		if (iChangingName < LEN_NAME)
		{
			scanf_s("%c", changingName[iChangingName]);
			iChangingName++;
		}
		else
		{
			changingName = realloc(changingName, iChangingName + 2);
			scanf_s("%c", changingName[iChangingName]);
			iChangingName++;
			changingName[iChangingName] = '\0';
		}
	}
	*/
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