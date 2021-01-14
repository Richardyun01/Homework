#include <stdio.h>

int main()
{
    int count = 0;
    int input;

    scanf("%d", &input);

    while (1) {
        if (input % 5 == 0) {
            count += input / 5;
            printf("%d\n", count);
            break;
        }

        input = input - 3;
        count++;

        if (input < 0) {
            printf("-1\n");
            break;
        }
    }

    return 0;
}
