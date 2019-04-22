#ifndef TYPES
#define TYPES

typedef enum FuncResult_ { FAIL, SUCCESS } func_result_t;

typedef enum OperationCode_ 
{
	NULL_OPERATION = 0,
	EXIT = 'e'
} operation_code_t;

typedef struct Node_
{
	char* name;
	node_t* parent;
	int childrenNum;
	node_t* child;
	char* data; //NULL если это папка
} node_t;

#endif