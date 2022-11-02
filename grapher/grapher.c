#include "grapher.h"

/*---CONSOLE OPERATIONS---*/
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

/*---HELPER FUNCTIONS---*/

static void setBlueColor(HANDLE hConsole) {
    /*sets the red color to the console*/
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE |
        FOREGROUND_INTENSITY);
}

static void setRedColor(HANDLE hConsole) {
    /*sets the red color to the console*/
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED |
        FOREGROUND_INTENSITY);
}

static void setGreenColor(HANDLE hConsole) {
    /*sets the green color to the console*/
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN |
        FOREGROUND_INTENSITY);
}

static void printEndLine(HANDLE hConsole) {
    /*prints 'x' at the end of the console*/
    setBlueColor(hConsole);
    SetConsoleCursorPosition(hConsole, brgt);
    printf("x");
}

static bool drawGraph(HANDLE hConsole, COORD winSize) {
    /*summary: draw the skeleton of the graph
    args:
        HANDLE hConsole -> console output
        COORD winSize -> size of the window
    */
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

    /*marking the x positive quadrant*/
    while (xPos.X >= t_xPos.X) {
        SetConsoleCursorPosition(
            hConsole, t_xPos);
        printf("-");
        t_xPos.X++;
    }

    setGreenColor(hConsole);
    
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

    setBlueColor(hConsole);

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

    printEndLine(hConsole);

    return 1;
}


static bool drawTable(HANDLE hConsole, COORD winSize) {
    /*summary: draws the table for the coordinates
    args:
        HANDLE hConsole -> console output
        COORD winSize -> size of window
    
    x------x------x
    |cc    |      |
    |cc  --x--    |
    |cc    |      |
    x------x------x
    
    The table is placed at the left corner; The coordinates
    will be added to the table;
    */

    /*printing the headers of the table*/
    COORD tcoord = { tlft.X , tlft.Y + 1 };
    SetConsoleCursorPosition(hConsole, tcoord);
    setGreenColor(hConsole);
    printf(" coordinates ");

    /*iterating through coordinates*/
    int tSize = 0;
    while (GlobalContainer.size > tSize) {
        SetConsoleCursorPosition(
            hConsole, tcoord);
        /*obtaining the x and y val*/
        printf("%d->(%d, %d)", tSize + 1 , 1, 2);
        tcoord.Y++;
    }


    printEndLine(hConsole);
    return true;
}


/*---MAIN FUNCTIONS---*/
bool InitConsole(void) {
    /*setting up the input and output handles*/
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hstdin = GetStdHandle(STD_INPUT_HANDLE);

    /*clears the screen*/
    cls(hstdout);

    if (!GetConsoleScreenBufferInfo(hstdout, &csbiInfo)) {
        return false;
    }

    /*
    removing the scroll buffer
    */
    // current window size
    short winWidth = csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1;
    short winHeight = csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top + 1;
    // current screen buffer size
    short scrBufferWidth = csbiInfo.dwSize.X;

    COORD newSize = { scrBufferWidth, winHeight };

    if ((MINSIZEX >= scrBufferWidth)
        || (MINSIZEY >= winHeight)) {
        fprintf(stderr, "Console Size Is Too Small;"
            "The Minimum Size Should Be 120x30");
        return false;
    }

    if (!SetConsoleScreenBufferSize(
        hstdout, newSize)) {
        return false;
    }

    /*adjusting new size with the reduced buffer size*/
    COORD consoleSize = {
        scrBufferWidth - 1, winHeight - 3 };

    /*setting up the coordinates*/
    tlft.X = 0;
    tlft.Y = 0;
    tmid.X = consoleSize.X / 2;
    tmid.Y = 0;
    trgt.X = consoleSize.X - 1;
    trgt.Y = 0;
    mmid.X = consoleSize.X / 2;
    mmid.Y = consoleSize.Y / 2;
    blft.X = 0;
    blft.Y = consoleSize.Y;
    bmid.X = consoleSize.X / 2;
    bmid.Y = consoleSize.Y;
    brgt.X = consoleSize.X - 1;
    brgt.Y = consoleSize.Y;
    btl.X = 0;
    btl.Y = consoleSize.Y + 1;

    drawGraph(hstdout, consoleSize);
    drawTable(hstdout, consoleSize);
	return true;
}

