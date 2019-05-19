#include "Common.h"

status_t createNode()
{
	//получить тип (файл или папка)
	//получить название
	//создать (добавить ребёнка cur)
	return SUCCESS;
}

status_t deleteNode()
{
	//получить название
	//удалить (удалить нужного ребёнка cur и всех его детей)
	return SUCCESS;
}

status_t renameNode()
{
	//получить название
	//получить новое название
	//переименовать
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

int getChildID()
{
	int childID = 0;
	printf("Print ID of file which you want to open: ");
	scanf("%i", &childID);
	return childID;
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