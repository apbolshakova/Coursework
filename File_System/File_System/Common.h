#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#include "Constants.h"
#include "Types.h"

extern node_t* root;
extern node_t* cur; //folder or file to work with

/*Main.c*/
void handleMainCycle();
status_t printCurNode();
status_t printPath(); //TODO for Angela
status_t printContents(); //TODO for Angela
void printMainMenu();
actionID_t getID(); //TODO for Angela
status_t handleAction(actionID_t action);

/*FileSystem.c*/
status_t getFS();
status_t initFS(); //TODO for Angela
status_t loadFS(); //TODO for Angela
status_t flushFS(); //TODO for Angela
status_t deleteFS(); //TODO for Sasha

/*Node.c*/
status_t createNode(); //TODO for Sasha
status_t deleteNode(); //TODO for Sasha
status_t renameNode(); //TODO for Sasha
status_t openNode();
int getChildID();
status_t closeNode();

/*File.c*/
status_t editFile(); //TODO for Sasha