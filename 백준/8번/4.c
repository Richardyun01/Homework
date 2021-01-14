#include <stdio.h>

#define MAX 1000000

int main()
{
    int go, fall, top;
    int day = 1;

    scanf("%d%d%d", &go, &fall, &top);

    while (day > 0) {
        day++;
        if (top < (go*day) + (fall*(day - 1))) {
            printf("%d", day);
            break;
        }
    }

    return 0;
}
