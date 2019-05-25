#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
#include "Types.h"

extern node_t* root;
extern node_t* cur; //folder or file to work with

/*Main.c*/
void handleMainCycle();
status_t printCurNode();
status_t printDir();
status_t printContents();
void printText(char* text);
void printMainMenu();
actionID_t getID();
status_t handleAction(actionID_t action);

/*FileSystem.c*/
status_t getFS();
status_t initFS();
status_t handleLoading();
status_t loadFS(const char *fileName);
status_t getNodes(node_t** node, node_t* parent, FILE* file);
status_t getDataFromFile(char** storage, FILE* file);
status_t handleFlushing();
status_t flushFS(const char *fileName);
status_t printNodes(node_t* node, FILE* file);
void fprintText(char* text, FILE* file);
char* getFileName();
status_t deleteFS(); //TODO for Sasha

/*Node.c*/
status_t createNode(); //TODO for Sasha
void deleteChildrenRecur(node_t* curRecur);
status_t deleteNode(); //TODO for Sasha
int getChildID();
status_t renameNode(); //TODO for Sasha
status_t openNode();
status_t closeNode();


/*File.c*/
status_t editFile(); //TODO for Sasha

/*Path.c*/
status_t getPath(path_t** path);
status_t pushIntoPath(path_t** root, node_t* node);
status_t printPath(path_t* root);
void deletePath(path_t** root);