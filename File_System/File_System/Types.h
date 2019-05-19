#ifndef TYPES
#define TYPES

typedef enum Status_ { FAIL, SUCCESS } status_t;

typedef enum ActionID_
{
	invalidID,
	initID,
	loadID,
	flushID,
	createID,
	deleteID,
	renameID,
	openID,
	closeID,
	editID,
	exitID,
	countID
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