#ifndef GRAPHER_H
#define GRAPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#include "coordcontainer.h"

/*handles the console input and output*/
static HANDLE hstdout, hstdin;
/*stores the console buffer information*/
static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

/*Console Screen Size*/
static short MINSIZEX = 119;
static short MINSIZEY = 29;

/*XRANGE : 15 >= x >= 15*/
static short XRANGE = 20;
/*YRANGE : 15 >= y >= 15*/
static short YRANGE = 10;

/*
structure that holds the basic information
about the coordinatecontainer
*/
typedef struct GlobalContainer {
	coordcontainer_t* HEAD;
	int size;
} glbcontainer_t;

static glbcontainer_t GlobalContainer = { NULL,0 };


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
*/
static COORD tlft;
static COORD tmid;
static COORD trgt;
static COORD mmid;
static COORD blft;
static COORD bmid;
static COORD brgt;
static COORD btl;

/*initialize the console*/
bool InitConsole();

/*clears the screen*/
void cls(HANDLE hConsole);

/*draws the skeleton of the graph*/
static bool drawGraph(HANDLE hConsole, COORD winSize);
/*draws the coordinates table*/
static bool drawTable(HANDLE hConsole, COORD winSize);


/*helper functions*/
/*endline*/
static void printEndLine(HANDLE hConsole);

/*color function sets color to text*/
static void setBlueColor(HANDLE hConsole);
static void setRedColor(HANDLE hConsole);
static void setGreenColor(HANDLE hConsole);

#endif // GRAPHER_H

