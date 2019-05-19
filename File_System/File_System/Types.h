#ifndef TYPES
#define TYPES

typedef enum Status_ { FAIL, SUCCESS } status_t;

typedef enum ActionID_
{
	invalidID,
	initID = 'i',
	loadID = 'l',
	flushID = 'f',
	createID = 'n',
	deleteID = 'd',
	renameID = 'r',
	openID = 'o',
	closeID = 'c',
	editID = 'e',
	exitID = '\033'
} actionID_t;

typedef struct Node_
{
	char* name;
	char type; //F - folder, T - text file
	struct Node_* parent;
	int childrenNum;
	struct Node_** child;
	char* data; //NULL if it's folder
} node_t;

#endif