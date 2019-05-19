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

status_t openNode() //TODO test
{
	int childID = getChildID();
	if (cur->childrenNum <= childID)
	{
		print("ERROR: attempt to open not existing file.\n");
		return FAIL;
	}
	cur = cur->child[childID];
	return SUCCESS;
}

status_t closeNode() //TODO test
{
	if (!cur->parent)
	{
		printf("ERROR: attempt to close root.\n");
		return FAIL;
	}
	cur = cur->parent;
	return SUCCESS;
}