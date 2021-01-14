#include <stdio.h>

int main()
{
    int a, b, c;

    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (a*a == b*b + c*c) {
            printf("true\n");
        } else if (a*a + b*b == c*c) {
            printf("true\n");
        } else if (a*a + c*c == b*b) {
            printf("true\n");
        } else {
            printf("false\n");
        }

        if (a == 0 && b == 0 && c == 0) break;
    }

    return 0;
}
