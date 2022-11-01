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


void setBlueColor(HANDLE hConsole) {
    /*sets the red color to the console*/
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE |
        FOREGROUND_INTENSITY);
}

void setRedColor(HANDLE hConsole) {
    /*sets the white color to the console*/
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED |
        FOREGROUND_INTENSITY);
}


void drawGraph(HANDLE hConsole, COORD winSize) {
    /*summary: draw the skeleton of the graph
    args:
        HANDLE hConsole -> console output
        COORD winSize -> size of the window
    More:
              y = x 
                | / 
				|/
		  ------0------
			   /|
			  / |

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

    short tempY = 0;
    short botY = winSize.Y;

    COORD tlft = {0 , 0};
    COORD tmid = { winSize.X / 2, 0 };
    COORD trgt = { winSize.X - 1, 0};

    COORD mmid = { winSize.X / 2, winSize.Y / 2 };

    COORD blft = { 0 , winSize.Y };
    COORD bmid = { winSize.X / 2 , winSize.Y };
    COORD brgt = { winSize.X - 1, winSize.Y };

    COORD btl = { 0, winSize.Y + 1 };

    /*setting console attributes*/
    setBlueColor(hConsole);

    /*placing cursors*/
    SetConsoleCursorPosition(hConsole, tlft);
    printf("x");
    SetConsoleCursorPosition(hConsole, tmid);
    printf("x");
    SetConsoleCursorPosition(hConsole, trgt);
    printf("x");
    SetConsoleCursorPosition(hConsole, blft);
    printf("x");
    SetConsoleCursorPosition(hConsole, bmid);
    printf("x");
    SetConsoleCursorPosition(hConsole, brgt);
    printf("x");
    SetConsoleCursorPosition(hConsole, brgt);
    printf("x");

    /*drawing the skeleton of the graph*/
    /*moving cursor to mid and placing origin*/
    SetConsoleCursorPosition(hConsole, mmid);
    printf("0");

    /*drawing x range*/
    COORD xNeg = { mmid.X - XRANGE, mmid.Y };
    COORD xPos = { mmid.X + XRANGE, mmid.Y };

    /*temp variables used for iteration*/
    COORD t_xNeg = { mmid.X - 1, mmid.Y };
    COORD t_xNegNum = { mmid.X - 1, mmid.Y  + 1};
    COORD t_xPos = { mmid.X + 1, mmid.Y };
    COORD t_xPosNum = { mmid.X + 1, mmid.Y  + 1};
    
    /*marking the x negative quadrant*/
    while (xNeg.X <= t_xNeg.X) {
        SetConsoleCursorPosition(
            hConsole, t_xNeg);
        printf("-");
        t_xNeg.X--;
    }

    /*marking the x number line*/
    while (xNeg.X <= t_xNegNum.X) {
        SetConsoleCursorPosition(
            hConsole, t_xNegNum);
        int val = t_xNegNum.X - mmid.X;
        if (val % 2 == 0){
            printf("%d", val / 2);
        }
        t_xNegNum.X--;
    }
    

    /*marking the x positive quadrant*/
    while (xPos.X >= t_xPos.X) {
        SetConsoleCursorPosition(
            hConsole, t_xPos);
        printf("-");
        t_xPos.X++;
    }

    /*marking the x number line*/
    while (xPos.X >= t_xPosNum.X) {
        SetConsoleCursorPosition(
            hConsole, t_xPosNum);
        int val = t_xPosNum.X - mmid.X;
        if (val % 2 == 0){
            printf("%d", val / 2);
        }
        t_xPosNum.X++;
    }

    /*drawing y range*/
    COORD yNeg = { mmid.X,
        mmid.Y - YRANGE };
    COORD yPos = { mmid.X,
        mmid.Y + YRANGE };

    /*temp variables used
    for iteration*/
    COORD t_yNeg = { mmid.X,
        mmid.Y - 1 };
    COORD t_yPos = { mmid.X,
        mmid.Y + 1 };

    while (yNeg.Y <= t_yNeg.Y) {
        SetConsoleCursorPosition(
            hConsole, t_yNeg);
        printf(
            "|%d", mmid.Y - t_yNeg.Y);
        t_yNeg.Y--;
    }

    while (yPos.Y >= t_yPos.Y) {
        SetConsoleCursorPosition(
            hConsole, t_yPos);
        printf("|%d", mmid.Y - t_yPos.Y);
        t_yPos.Y++;
    }

    SetConsoleCursorPosition(hConsole, brgt);
    printf("x");

    return;
}

void InitConsole(void) {
	/*setting up the input and output handles*/
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hstdin = GetStdHandle(STD_INPUT_HANDLE);

    XRANGE = 20;
    YRANGE = 10;

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

    /*adjusting new size with the reduced buffer size*/
    COORD consoleSize = {
        scrBufferWidth - 1, winHeight - 3};

    drawGraph(hstdout, consoleSize);

	return;
}


