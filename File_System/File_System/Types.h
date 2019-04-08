#ifndef TYPES
#define TYPES

typedef enum FuncResult_ { FAIL, SUCCESS } func_result_t;

typedef struct Node_
{
	char* name;
	node_t* parent;
	int childrenNum;
	node_t* child;
	char* data;
} node_t;

#endif