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
status_t printInterface();
status_t printPath(); //TODO for Angela
status_t printContents(); //TODO for Angela
void printMainMenu(); //TODO for Angela
actionID_t getID(); //TODO for Angela
status_t handleAction(actionID_t action); //TODO for Angela

/*FileSystem.c*/
status_t getFS(); //TODO for Angela
status_t initFS(); //TODO for Angela
status_t loadFS(); //TODO for Angela
status_t flushFS(); //TODO for Angela

/*Handler.c*/
status_t handleOpening(); //TODO for Angela
status_t handleClosing(); //TODO for Angela

/*Node.c*/
status_t createNode(); //TODO for Sasha
status_t deleteNode(); //TODO for Sasha
status_t renameNode(); //TODO for Sasha

/*Folder.c*/

/*File.c*/
status_t editFile(); //TODO for Sasha