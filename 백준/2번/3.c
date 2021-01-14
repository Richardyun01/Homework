#include <stdio.h>

int main()
{
    int year;
    int a, b, c;

    scanf("%d", &year);

    a = year % 4;
    b = year % 100;
    c = year % 400;

    if (a == 0 && b != 0) {
        printf("1\n");
    } else if (c == 0) {
        printf("1\n");
    } else {
        printf("0");
    }

    return 0;
}
