#ifndef GRAPHER_H
#define GRAPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#include "coordcontainer.h"
#include "inputstring.h"
#include "parser.h"

/*handles the console input and output*/
static HANDLE hstdout, hstdin;
/*stores the console buffer information*/
static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
/*input event in the console input buffer*/
static INPUT_RECORD irInBuf[MAXCHARCOUNT - 1];

/*Console Screen Size*/
static short MINSIZEX = 119;
static short MINSIZEY = 29;

/*XRANGE : 15 >= x >= 15*/
static short XRANGE = 20;
/*YRANGE : 15 >= y >= 15*/
static short YRANGE = 10;

/*
structure that holds the information
about the input string
*/
static inputstring_t* INPUTSTRING = NULL;

/**/
static int CURRENTCHARCOUNT;


/*
structure that holds the basic information
about the coordinatecontainer
*/
typedef struct GlobalContainer {
	coordcontainer_t* HEAD;
	int size;
} glbcontainer_t;

static glbcontainer_t GlobalContainer = {
	.HEAD = NULL, .size = 0 };


/*
console:
   tlft   tmid    trgt
   x----------------x
   |       mm       |
   x----------------x
   blft   bmid    brgt

setting the predefined cursor position
---
tlft -> top left point
tmid -> top mid point
trgt -> top right point
---
mmid -> mid point
---
blft -> bot left point
bmid -> bot mid point
brgt -> bot right point
---
*/
static COORD* tlft;
static COORD* tmid;
static COORD* trgt;
static COORD* mmid;
static COORD* blft;
static COORD* bmid;
static COORD* brgt;
static COORD* btl;

/*initialize the console*/
bool InitConsole();
/*main console function*/
int MainConsole();

/*initialize the console coordinates*/
void InitConsoleCoordinates(COORD consolesize);
/*free the memory of all console coordinates*/
void FreeConsoleCoordinates();

/*clears the screen*/
void cls(HANDLE hConsole);
/*clears the given line*/
void clsLine(COORD line, bool ret);
/*clears the character*/
void clsChar(COORD line, bool ret);

/*draws the skeleton of the graph*/
static bool drawGraph(COORD winSize);
/*draws the coordinates table*/
static bool drawTable(COORD winSize);
/*processing keyevents*/
static void processKeyEvent(KEY_EVENT_RECORD key);

/*helper functions*/
/*endline*/
static void printEndLine(HANDLE hConsole);

/*color function sets color to text*/
void setBlueColor();
void setRedColor();
void setGreenColor();


#endif // GRAPHER_H

