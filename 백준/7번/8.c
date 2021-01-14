#include <stdio.h>
#include <string.h>

#define MAX 16

int main()
{
    char str[MAX] = {0,};
    char c;
    int cnt = 0;

    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        c = str[i];

        if (c == 'A' || c == 'B' || c == 'C') cnt += 3;
        else if (c == 'D' || c == 'E' || c == 'F') cnt += 4;
        else if (c == 'G' || c == 'H' || c == 'I') cnt += 5;
        else if (c == 'J' || c == 'K' || c == 'L') cnt += 6;
        else if (c == 'M' || c == 'N' || c == 'O') cnt += 7;
        else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') cnt += 8;
        else if (c == 'T' || c == 'U' || c == 'V') cnt += 9;
        else if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z') cnt += 3;
    }

    printf("%d", cnt);

    return 0;
}
