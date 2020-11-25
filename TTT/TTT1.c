#include <stdio.h>
#include <string.h>
#include <windows.h>

#define BOARD_SIZE 3 // 3x3

static int screen_cols, screen_rows;

//////////////////////////////////////////////////////////

void getScreenSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    screen_cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    screen_rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    //printf("Screen Size: %d x %d\n", screen_cols, screen_rows);
}

void clearLine(int row)
{
    for (int i =0; i < screen_cols; i++) {
        COORD coord = {i, row};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf(" ");
    }
}

void printLine(const char *str, int col, int row)
{
    COORD coord = {(col < 0) ? (screen_cols - strlen(str)) / 2 : col, row};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%s", str);
}

void printCell(COORD coord, int val)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("   ");

    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    switch (val) {
    case 1:
        printf(" X ");
        break;
    case 2:
        printf(" O ");
        break;
    default:
        printf("   ");
        break;
    }

    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("   ");
}

void printBoard(int board[], int human_turn)
{
    int line = 1;
    printLine("### Tic-Tac-Toe ###", -1, line);
    line += 2;

    if (1 == human_turn)
        printLine("Human: X, Computer: O", -1, line);
    else // 2 == menu
        printLine("Human: O, Computer: X", -1, line);
    line += 2;

    COORD base_coord = { (screen_cols - BOARD_SIZE*3) / 2, line };
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        int x = i % BOARD_SIZE;
        int y = i / BOARD_SIZE;
        COORD coord = { base_coord.X + x*3, base_coord.Y + y*3 };

        if (i & 1) { // switch cell color
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                BACKGROUND_RED|BACKGROUND_GREEN); // yellow/black
        } else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE); // white/black
        }
        printCell(coord, board[i]);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE); // restore black/white
}

int startMenu()
{
    int input;
    system("cls");
    do {
        printf("### Tic-Tac-Toe ###\n");
        printf("1: Play first (X)\n");
        printf("2: Play second (O)\n");
        printf("3: Exit\n");
        printf("Enter command: ");
        scanf("%d", &input);
        system("cls");
    } while (1 > input || input > 3);
    return input;
}

int powi(int a, int n)
{
    int p = 1;
    for (int i = 0; i < n; i++) p*= a;
    return p;
}

int countBoardLine(int board[], int dir)
{
    int count = 1;
    if (dir < BOARD_SIZE) {
        int p = dir * BOARD_SIZE;
        for (int i = 0; i < BOARD_SIZE; i++, p++)
            count *= board[p] + 1;
    } else if (dir < BOARD_SIZE*2) {
        int p = dir - BOARD_SIZE*2;
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE)
            count *= board[p] + 1;
    } else if (dir == BOARD_SIZE*2) {
        int p = 0;
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE+1)
            count *= board[p] + 1;
    } else {
        int p = BOARD_SIZE-1;
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE-1)
            count *= board[p] + 1;
    }
    return count;
}

int findMakePos(int board[], int dir)
{
    if (dir < BOARD_SIZE) {
        int p = dir * BOARD_SIZE;
        for (int i = 0; i < BOARD_SIZE; i++, p++)
            if (0 == board[p]) return p;
    } else if (dir < BOARD_SIZE*2) {
        int p = dir - BOARD_SIZE;
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE)
            if (0 == board[p]) return p;
    } else if (dir == BOARD_SIZE*2) {
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE+1)
            if (0 == board[p]) return p;
    } else {
        int p = BOARD_SIZE-1;
        for (int i = 0; i < BOARD_SIZE; i++, p+=BOARD_SIZE-1)
            if (0 == board[p]) return p;
    }
}

int playHuman(int board[], int human_turn)
{
    int pos, line = BOARD_SIZE*3 + 6;
    clearLine(line);
    printLine("Your turn: ", -1, line);

    while (1) {
        scanf("%d", &pos);
        pos -= 1;
        if (pos < 0 || pos > BOARD_SIZE*BOARD_SIZE-1 || 0 != board[pos]) {
            clearLine(line);
            printLine("Enter again: ", -1, line);
        } else break;
    }
    return pos;
}

int playComputer(int board[], int human_turn)
{
    int pos;

    // 1: try making
    for (int i = 0; i < BOARD_SIZE*2+2; i++) {
        int count = countBoardLine(board, i);
        if ((1 == human_turn && count == powi(3, BOARD_SIZE-1)) ||
            (2 == human_turn && count == powi(2, BOARD_SIZE-1))) {
            return findMakePos(board, i);
        }
    }

    // 2: defend making
    for (int i = 0; i < BOARD_SIZE*2+2; i++) {
        int count = countBoardLine(board, i);
        if ((1 == human_turn && count == powi(2, BOARD_SIZE-1)) ||
            (2 == human_turn && count == powi(3, BOARD_SIZE-1))) {
            return findMakePos(board, i);
        }
    }

    // 3: sequence priority(3x3)
    static int priority[9] = {4, 1, 3, 5, 7, 0, 2, 6, 8};
    for (int i = 0; i < 9; i++) {
        pos = priority[i];
        if (0 == board[pos]) return pos;
    }
}

int checkWin(int board[], int human_turn)
{
    int line = BOARD_SIZE*3 + 6;
    clearLine(line);

    for (int i = 0; i < BOARD_SIZE*2+2; i++) {
        int count = countBoardLine(board, i);
        if (count == powi(2, BOARD_SIZE)) { // made X
            if (1 == human_turn) {
                printLine("Human Win", -1, line);
            } else {
                printLine("Computer Win", -1, line);
            }
            return 1; // end game
        } else if (count == powi(3, BOARD_SIZE)) { // made O
            if (2 == human_turn) {
                printLine("Human Win", -1, line);
            } else {
                printLine("Computer Win", -1, line);
            }
            return 1; // end game
        }
    }

    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        if (0 == board[i]) return 0; // if empty cell->continue game
    }

    // if full
    printLine("Draw", -1, line);
    return 1; // end game
}

////////////////////////////////////////////////////////////////////////////

void playGame()
{
    int board[BOARD_SIZE*BOARD_SIZE] = {0,};
    int human_turn = startMenu();
    if (3 == human_turn) return; // exit

    int turn = 1; // start with 'X'
    printBoard(board, human_turn);
    while (1) {
        int pos;
        if (turn == human_turn)
            pos = playHuman(board, human_turn)
        else
            pos = playComputer(board, human_turn);

        board[pos] = turn; // set board
        turn = 3 - turn; // switch turn (1->2, 2->1)

        printBoard(board, human_turn);
        if (checkWin(board, human_turn)) break;
    }
}

int main()
{
    getScreenSize();
    while (1) {
        playGame();

        int line = BOARD_SIZE*3 + 8;
        while (1) {
            char c;
            clearLine(line);
            printLine("Play again? (Y/N): ", 0, line);
            scanf("%c", &c);
            if (c == 'N' || c == 'n') return 0; // exit program
            else if (c == 'Y' || c == 'y') break;
        }
    }

    return 0;
}
