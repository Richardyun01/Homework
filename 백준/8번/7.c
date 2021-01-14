#include <stdio.h>

int main()
{
    int count = 0;
    int box;

    scanf("%d", &box);

    while (1) {
        if (box % 5 == 0) {
            count += box / 5;
            printf("%d", count);
            break;
        }

        box = box - 3;
        count++;

        if (box < 0) {
            printf("-1");
            break;
        }
    }

    return 0;
}
