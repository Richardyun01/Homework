#include <stdio.h>
#include <string.h>
#include <windows.h>

#define BOARD_SIZE  3   // 3 x 3
#define MAX_STR 64

static int screen_cols, screen_rows;

void getScreenSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    screen_cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    screen_rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    printf("Screen Size: %d x %d\n", screen_cols, screen_rows);
}

void printStrCenter(const char *str, int row)
{
    COORD coord = { (screen_cols - strlen(str)) / 2, row };
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
    default: // 0
        printf("   ");
        break;
    }

    coord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("   ");
}

void printBoard(int board[], int size, int row)
{
    COORD base_coord = { (screen_cols - size*3) / 2, row };
    for (int i = 0; i < size*size; i++) {
        int x = i % size;
        int y = i / size;
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

/* 2 3 5
   7 11 13
   17 19 23 */
/* void result()
{
    int x, o;

    if (x == 2*3*5 || x == 7*11*13 || x == 17*19*23
       || x == 2*7*17 || x == 3*11*19 || x == 5*13*23
       || x == 2*11*23 || x == 5*11*17) {
        printf("First Wins!\n");
    } else if (o == 2*3*5 || o == 7*11*13 || o == 17*19*23
       || o == 2*7*17 || o == 3*11*19 || o == 5*13*23
       || o == 2*11*23 || o == 5*11*17) {
        printf("Second Wins!\n");
    } else {
        printf("Draw.\n");
    }
} */

void firstX()
{
    int board[BOARD_SIZE*BOARD_SIZE] = { 0, };
    int turn = 1;

    getScreenSize();
    while (1) {
        int pos, row = 1;
        row += 2;
        printBoard(board, BOARD_SIZE, row);

        row += BOARD_SIZE*3 + 1;
        printStrCenter("                ", row); // clear previous
        printStrCenter("Your turn: ", row);

        while (1) {
            scanf("%d", &pos);
            if (pos < 1 || pos > BOARD_SIZE*BOARD_SIZE || board[pos-1] != 0) {
                printStrCenter("                ", row); // clear previous
                printStrCenter("Enter again: ", row);
            } else break;
        }

        board[pos-1] = turn; // set board
        turn = 3 - turn; // switch turn (1 -> 2, 2 -> 1)
    }
}

void firstO()
{
    int board[BOARD_SIZE*BOARD_SIZE] = { 0, };
    int turn = 1;

    getScreenSize();
    while (1) {
        int pos, row = 1;
        row += 2;
        printBoard(board, BOARD_SIZE, row);

        row += BOARD_SIZE*3 + 1;
        printStrCenter("                ", row); // clear previous
        printStrCenter("Your turn: ", row);

        while (1) {
            scanf("%d", &pos);
            if (pos < 1 || pos > BOARD_SIZE*BOARD_SIZE || board[pos-1] != 0) {
                printStrCenter("                ", row); // clear previous
                printStrCenter("Enter again: ", row);
            } else break;
        }

        board[pos-1] = turn; // set board
        turn = 3 - turn; // switch turn (1 -> 2, 2 -> 1)
    }
}

int main()
{
    int board[BOARD_SIZE*BOARD_SIZE] = { 0, };
    int turn = 1;
    int pos, row = 1;

    getScreenSize();

    printStrCenter("### Tic-Tac-Toe ###", row);

    row += 1;
    printStrCenter("1: Play first (X)", row);

    row += 1;
    printStrCenter("2: Play second (O)", row);

    row += 1;
    printStrCenter("3: Exit", row);

    row += 1;
    printStrCenter("Enter command: ", row);

    row += 1;
    while(1) {
        char str[MAX_STR];
        int command;

        fgets(str, MAX_STR, stdin);
        command = atoi(str);

        switch (command) {
        case 1:
            firstX;
            break;
        case 2:
            firstO;
            break;
        case 3:
            return 0;
        default:
            printf("Wrong command. Try again: ");
            continue;
        }
    }

    return 0;
}
