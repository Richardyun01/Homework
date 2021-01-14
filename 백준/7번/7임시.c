#include <stdio.h>

int main()
{
    char a[4], b[4];
    int i, j;

    scanf("%s%s", a, b);

    for (i = 2; i >= 0; i--) {
        if (a[i] < b[i]) {
            for (j = 2; j >= 0; j--) {
                printf("%c", b[j]);
            }
            break;
        } else if (b[i] < a[i] ) {
            for (j = 2; j >= 0; j--) {
                printf("%c", a[j]);
            }
            break;
        }
    }

    return 0;
}
