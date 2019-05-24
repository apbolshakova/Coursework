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
	system("cls");
	switch (action)
	{
	case initID: return initFS(); break;
	case loadID: return handleLoading();
	}
	return FAIL;
}

status_t initFS()
{
	root = (node_t*)malloc(sizeof(node_t));
	if (!root)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	root->name = ROOT_NAME;
	root->type = 'F';
	root->parent = NULL;
	root->childrenNum = 0;
	root->child = NULL;
	root->data = NULL;
	return SUCCESS;
}

status_t handleLoading()
{
	char* fileName = getFileName();
	if (!fileName)
	{
		printf("ERROR: unable to get file name");
		return FAIL;
	}
	if (loadFS(fileName) == FAIL)
	{
		free(fileName);
		printf("ERROR: unable to load file system from file.\n");
		return FAIL;
	}
	free(fileName);
	return SUCCESS;
}

status_t loadFS(const char *fileName)
{
	FILE* file;
	if (!(file = fopen(fileName, "r")))
	{
		printf("ERROR: unable to open file.\n");
		return FAIL;
	}
	if (getNodes(&root, NULL, file) == FAIL)
	{
		printf("ERROR: unable to handle data from file.\n");
		return FAIL;
	}
	fclose(file);
	return SUCCESS;
}

status_t getNodes(node_t** node, node_t* parent, FILE* file)
{
	*node = (node_t*)malloc(sizeof(node_t));
	if (!*node)
	{
		deleteFS();
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}

	char* name = (char*)calloc(LEN, sizeof(char));
	if (!name)
	{
		deleteFS();
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	int childrenNum = INVALID;
	char* data = NULL;
	fscanf_s(file, LEN_CODE, name, LEN);
	fscanf_s(file, "%i", &childrenNum);
	if (childrenNum == INVALID && getDataFromFile(&data, file) == FAIL)
	{
		deleteFS();
		printf("ERROR: unable to load data for text file.\n");
		return FAIL;
	}

	(*node)->name = name;
	(*node)->childrenNum = childrenNum;
	(*node)->parent = parent;
	if (childrenNum == INVALID)
	{
		(*node)->type = 'T';
		(*node)->child = NULL;
		(*node)->data = data;
	}
	else
	{
		(*node)->type = 'F';
		(*node)->child = (node_t**)malloc(childrenNum * sizeof(node_t*));
		(*node)->data = NULL;
	}

	for (int i = 0; i < (*node)->childrenNum; i++)
	{
		if (getNodes(&((*node)->child[i]), *node, file) == FAIL)
		{
			deleteFS();
			return FAIL;
		}
	}
	return SUCCESS;
}

status_t getDataFromFile(char** storage, FILE* file)
{
	char* data = (char*)calloc(LEN, sizeof(char));
	char ch = '\0';
	fscanf_s(file, "%c", &ch); //reads space
	do
	{
		fscanf_s(file, "%c", &ch);
		if (ch == EOF)
		{
			free(data);
			printf("ERROR: unexpected end of file.\n");
			return FAIL;
		}
		strncat(data, &ch, 1);
		if (strlen(data) % (LEN - 1) == 0)
			data = (char*)realloc(data, (strlen(data) + LEN) * sizeof(char));
	} while (ch != NEW_STRING);
	data[strlen(data) - 1] = '\0';
	*storage = data;
	return SUCCESS;
}

status_t handleFlushing()
{
	char* fileName = getFileName();
	if (!fileName)
	{
		printf("ERROR: unable to get file name");
		return FAIL;
	}
	if (flushFS(fileName) == FAIL)
	{
		free(fileName);
		printf("ERROR: unable to save file system in file.\n");
		return FAIL;
	}
	free(fileName);
	return SUCCESS;
}

status_t flushFS(const char *fileName)
{
	FILE* file;
	if (!(file = fopen(fileName, "w")))
	{
		printf("ERROR: unable to open file.\n");
		return FAIL;
	}
	if (printNodes(root, file) == FAIL)
	{
		printf("ERROR unable to save data in file.\n");
		return FAIL;
	}
	fclose(file);
	return SUCCESS;
}

status_t printNodes(node_t* node, FILE* file)
{
	if (!node) return FAIL;
	fprintf(file, "%s %i ", node->name, node->childrenNum);
	if (node->type == 'T') fprintText(node->data, file);
	fprintf(file, "\n");
	for (int i = 0; i < node->childrenNum; i++)
	{
		return printNodes(node->child[i], file);
	}
	return SUCCESS;
}

void fprintText(char* text, FILE* file)
{
	while (*text)
	{
		fprintf(file, "%c", *text);
		text++;
	}
	printf("\n");
}

char* getFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	printf("Enter name of file:\n");
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

status_t deleteFS()
{
	return SUCCESS;
}