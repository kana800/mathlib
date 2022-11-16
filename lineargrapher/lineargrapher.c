#include "lineargrapher.h"

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

void clsLine(COORD line, bool ret) {
    /*summary: clears the content
    of a given line and if 'ret' is
    true returns the original position
    args:
        COORD line -> coordinates of the line
        bool ret -> if true return original pos
    */

    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    /*Get the number of character cells in the current buffer.*/
    if (!GetConsoleScreenBufferInfo(
        hstdout, &csbi)){
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(
        hstdout,         /*Handle to console screen buffer*/
        (TCHAR)' ',      /*Character to write to the buffer*/
        dwConSize,       /*Number of cells to write*/
        line,     /*Coordinates of first cell*/
        &cCharsWritten)) /*Receive number of characters written*/
    {
        SetConsoleCursorPosition(hstdout, *btl);
        return;
    }
    SetConsoleCursorPosition(hstdout, *btl);
    return;
}

void clsChar(COORD line, bool ret) {
    /*summary: clears one character
    of a given line and if 'ret' is
    true returns the original position
    Ex:
        abcx 
        when clsChar is called x will be removed
        and if ret is true the cursor will move
        to pos of x;
    args:
        COORD line -> coordinates of the line
        bool ret -> if true return original pos
    */
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    /*Get the number of character cells in the current buffer.*/
    if (!GetConsoleScreenBufferInfo(
        hstdout, &csbi)){
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(
        hstdout,         /*Handle to console screen buffer*/
        (TCHAR)' ',      /*Character to write to the buffer*/
        dwConSize,       /*Number of cells to write*/
        line,     /*Coordinates of first cell*/
        &cCharsWritten)) /*Receive number of characters written*/
    {
        SetConsoleCursorPosition(hstdout, *btl);
        return;
    }
    btl->X--;
    SetConsoleCursorPosition(hstdout, *btl);
    return;
}

static void printEndLine(HANDLE hConsole) {
    /*prints 'x' at the end of the console*/
    setBlueColor(hConsole);
    SetConsoleCursorPosition(hConsole, *brgt);
    printf("x");
}

void setBlueColor() {
    /*summary: sets the red color to the console*/
    SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE |
        FOREGROUND_INTENSITY);
}

void setRedColor() {
    /*summary: sets the red color to the console*/
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED |
        FOREGROUND_INTENSITY);
}

void setGreenColor() {
    /*summary: sets the green color to the console*/
    SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN |
        FOREGROUND_INTENSITY);
}

static bool drawGraph(COORD winSize) {
    /*summary: draw the skeleton of the graph
    args:
        COORD winSize -> size of the window
    */
    /*setting console attributes*/
    setBlueColor();

    /*placing cursors*/
    SetConsoleCursorPosition(hstdout, *tlft);
    printf("x");
    SetConsoleCursorPosition(hstdout, *tmid);
    printf("x");
    SetConsoleCursorPosition(hstdout, *trgt);
    printf("x");
    SetConsoleCursorPosition(hstdout, *blft);
    printf("x");
    SetConsoleCursorPosition(hstdout, *bmid);
    printf("x");
    SetConsoleCursorPosition(hstdout, *brgt);
    printf("x");
    SetConsoleCursorPosition(hstdout, *brgt);
    printf("x");

    /*drawing the skeleton of the graph*/
    /*moving cursor to mid and placing origin*/
    SetConsoleCursorPosition(hstdout, *mmid);
    printf("0");

    /*drawing x range*/
    COORD xNeg = { mmid->X - XRANGE, mmid->Y };
    COORD xPos = { mmid->X + XRANGE, mmid->Y };

    /*temp variables used for iteration*/
    COORD t_xNeg = { mmid->X - 1, mmid->Y };
    COORD t_xNegNum = { mmid->X - 1, mmid->Y  + 1};
    COORD t_xPos = { mmid->X + 1, mmid->Y };
    COORD t_xPosNum = { mmid->X + 1, mmid->Y  + 1};
    
    /*marking the x negative quadrant*/
    while (xNeg.X <= t_xNeg.X) {
        SetConsoleCursorPosition(
            hstdout, t_xNeg);
        printf("-");
        t_xNeg.X--;
    }

    /*marking the x positive quadrant*/
    while (xPos.X >= t_xPos.X) {
        SetConsoleCursorPosition(
            hstdout, t_xPos);
        printf("-");
        t_xPos.X++;
    }

    setGreenColor(hstdout);
    
    /*marking the x number line*/
    while (xNeg.X <= t_xNegNum.X) {
        SetConsoleCursorPosition(
            hstdout, t_xNegNum);
        int val = t_xNegNum.X - mmid->X;
        if (val % 2 == 0){
            printf("%d", val / 2);
        }
        t_xNegNum.X--;
    }

    /*marking the x number line*/
    while (xPos.X >= t_xPosNum.X) {
        SetConsoleCursorPosition(
            hstdout, t_xPosNum);
        int val = t_xPosNum.X - mmid->X;
        if (val % 2 == 0){
            printf("%d", val / 2);
        }
        t_xPosNum.X++;
    }

    setBlueColor(hstdout);

    /*drawing y range*/
    COORD yNeg = { mmid->X,
        mmid->Y - YRANGE };
    COORD yPos = { mmid->X,
        mmid->Y + YRANGE };

    /*temp variables used
    for iteration*/
    COORD t_yNeg = { mmid->X,
        mmid->Y - 1 };
    COORD t_yPos = { mmid->X,
        mmid->Y + 1 };

    while (yNeg.Y <= t_yNeg.Y) {
        SetConsoleCursorPosition(
            hstdout, t_yNeg);
        printf(
            "|%d", mmid->Y - t_yNeg.Y);
        t_yNeg.Y--;
    }

    while (yPos.Y >= t_yPos.Y) {
        SetConsoleCursorPosition(
            hstdout, t_yPos);
        printf("|%d", mmid->Y - t_yPos.Y);
        t_yPos.Y++;
    }

    printEndLine(hstdout);

    return 1;
}

static bool drawTable(COORD winSize) {
    /*summary: draws the table for the coordinates
    args:
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
    COORD tcoord = { tlft->X , tlft->Y + 1 };
    SetConsoleCursorPosition(hstdout, tcoord);
    setGreenColor(hstdout);
    printf(" coordinates ");

    /*iterating through coordinates*/
    int tSize = 0;
    while (GlobalContainer.size > tSize) {
        SetConsoleCursorPosition(
            hstdout, tcoord);
        /*obtaining the x and y val*/
        printf("%d->(%d, %d)", tSize + 1 , 1, 2);
        tcoord.Y++;
    }


    printEndLine(hstdout);
    return true;
}

void InitConsoleCoordinates(COORD consolesize) {
    /*summary: allocates memory and initialize the
    console coordinates
    args: 
        COORD consolesize -> size of the console
    */

    /*allocating memory for the coordinates*/
    tlft = malloc(sizeof(COORD));
    tmid = malloc(sizeof(COORD)); 
    trgt = malloc(sizeof(COORD)); 
    mmid = malloc(sizeof(COORD)); 
    blft = malloc(sizeof(COORD)); 
    bmid = malloc(sizeof(COORD)); 
    brgt = malloc(sizeof(COORD)); 
    btl  = malloc(sizeof(COORD));


    /*setting up the coordinates*/
    tlft->X = 0;
    tlft->Y = 0;
    tmid->X = consolesize.X / 2;
    tmid->Y = 0;
    trgt->X = consolesize.X - 1;
    trgt->Y = 0;
    mmid->X = consolesize.X / 2;
    mmid->Y = consolesize.Y / 2;
    blft->X = 0;
    blft->Y = consolesize.Y;
    bmid->X = consolesize.X / 2;
    bmid->Y = consolesize.Y;
    brgt->X = consolesize.X - 1;
    brgt->Y = consolesize.Y;
    btl->X = 0;
    btl->Y = consolesize.Y + 1;

}

void FreeConsoleCoordinates() {
    /*summary: free memory of the 
    console coordinates*/
    free(tlft);
    free(tmid);
    free(trgt);
    free(mmid);
    free(blft);
    free(bmid);
    free(brgt);
    free(btl);
}

/*---MAIN FUNCTIONS---*/
bool InitConsole(void) {
    /*setting up the input and output handles*/
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hstdin = GetStdHandle(STD_INPUT_HANDLE);

    /*clears the screen*/
    cls(hstdout);

    if (!GetConsoleScreenBufferInfo(hstdout, &csbiInfo)) {
        fprintf(stderr, "Unable To Retrieve Buffer Information");
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

    InitConsoleCoordinates(consoleSize);

    drawGraph(consoleSize);
    drawTable(consoleSize);
   
	return true;
}

static void processKeyEvent(
    KEY_EVENT_RECORD key) {
    /*processes keyboard events and 
    add the characters to the static string*/
    CHAR asciichar = key.uChar.AsciiChar;

    if (key.bKeyDown) {
        printf("%c", asciichar);
        addChar(INPUTSTRING, asciichar);
        if (key.wVirtualKeyCode == VK_BACK) {
            removePrevChar(INPUTSTRING);
            clsChar(*INPUTSTRING->cursorpos, true);
        }
        else if (key.wVirtualKeyCode == VK_RETURN) {
            clearInputString(INPUTSTRING);
            /*parsing the string*/
            //bool parseret = parseString(INPUTSTRING);
            clsLine(*btl, true);
        }
    }

}

int MainConsole(void) {

    DWORD cNumRead, i;
    DWORD fdwMode = ENABLE_WINDOW_INPUT;
    CURRENTCHARCOUNT = 0;

    INPUTSTRING = CreateInputStringStruct(btl);

    /*setting the console mode*/
    if (!SetConsoleMode(hstdin, fdwMode)) {
        fprintf(stderr, "Unable To Set Mode");
        return false;
    }


    /*move the cursor to the bottom*/
    btl->Y -= 1;
    SetConsoleCursorPosition(hstdout, *btl);
    clsLine(*btl, true);


    while (1) {
        if (!ReadConsoleInput(
            hstdin,
            irInBuf,
            MAXCHARCOUNT - 1,
            &cNumRead
        )) {
            fprintf(stderr, "Cannot Process Line");
            break;
        }

        for (i = 0; i < cNumRead; i++) {
            switch (irInBuf[i].EventType) {
            case KEY_EVENT:
				processKeyEvent(irInBuf[i].Event.KeyEvent);
            default:
                break;
            }
        }
    }
    printEndLine(hstdout);
    FreeConsoleCoordinates();
    FreeInputString(INPUTSTRING);
    return 1;
}
