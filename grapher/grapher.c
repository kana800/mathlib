#include "grapher.h"

void cls(HANDLE hConsole) {
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
        (TCHAR)' ',      // Character to write to the buffer
        dwConSize,       // Number of cells to write
        coordScreen,     // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
        csbi.wAttributes, // Character attributes to use
        dwConSize,        // Number of cells to set attribute
        coordScreen,      // Coordinates of first cell
        &cCharsWritten))  // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}


void newLine(HANDLE hConsole, COORD cursorPos) {

}


void drawGraph(HANDLE hConsole, COORD winSize) {
    /*summary: draw the skeleton of the graph
    args:
        HANDLE hConsole -> console output
        COORD winSize -> size of the window
    */
    short startX = 0;
    short botY = winSize.Y;

    /*setting the cursor position to mid*/
    COORD topmidpoint = { winSize.X / 2, startX };
    SetConsoleCursorPosition(hConsole, topmidpoint);

    while (botY >= startX) {
        printf("|");
        topmidpoint.Y++;
        SetConsoleCursorPosition(hConsole, topmidpoint);
        startX++;
    }

    return;

}

void InitConsole(void) {
	/*setting up the input and output handles*/
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD cWritten;

    cls(hstdout);

	if (!GetConsoleScreenBufferInfo(hstdout, &csbiInfo)) {
		return;
	}

	/*
	removing the scroll buffer
	*/
	// current window size
	short winWidth = csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1;
	short winHeight = csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top + 1;
	// current screen buffer size
	short scrBufferWidth = csbiInfo.dwSize.X;
	short scrBufferHeight = csbiInfo.dwSize.Y;

	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;



	if (!SetConsoleScreenBufferSize(
		hstdout, newSize)) {
		return;
	}


    drawGraph(hstdout, newSize);

	return;
}


