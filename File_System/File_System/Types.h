#ifndef TYPES
#define TYPES

typedef enum Status_ { FAIL, SUCCESS } status_t;

typedef enum TypeOfCreate_ 
{
	invalidTC,
	folderTC='F', 
	textFileTC='T'
} create_type;

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

typedef struct Path_ //list of node pointers from root to cur
{
	node_t* node;
	struct Path_* next;
} path_t;

#endif