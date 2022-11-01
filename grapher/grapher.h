#ifndef GRAPHER_H
#define GRAPHER_H

#include <stdio.h>
#include <Windows.h>

/**/
static HANDLE hstdout, hstdin;
/*stores the console buffer information*/
static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

/*XRANGE : 15 >= x >= 15*/
static short XRANGE;
/*YRANGE : 15 >= y >= 15*/
static short YRANGE;


void InitConsole();
void cls(HANDLE hConsole);

/*draws the skeleton of the graph*/
void drawGraph(HANDLE hConsole, COORD winSize);


/*helper functions*/
/*color function sets color to text*/

void setBlueColor(HANDLE hConsole);
void setRedColor(HANDLE hConsole);


#endif // GRAPHER_H

