#ifndef GRAPHER_H
#define GRAPHER_H

#include <stdio.h>
#include <Windows.h>

/**/
static HANDLE hstdout, hstdin;
/*stores the console buffer information*/
static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

void InitConsole();
void cls(HANDLE hConsole);

/*draws the skeleton of the graph*/
void drawGraph(HANDLE hConsole, COORD winSize);
/*goes to a newline and moves the cursorpos to the 
given location
*/
void newLine(HANDLE hConsole, COORD cursorPos);


#endif // GRAPHER_H

