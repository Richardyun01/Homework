#include <stdio.h>

#define SIZE 15

int main()
{
    int T, i, j;
    int k, n;

    int apt[SIZE][SIZE] = {0,};

    for (i = 0; i < SIZE; i++) {
        apt[0][i] = i;
    }
    for (j = 0; j < SIZE; j++) {
        apt[j][1] = 1;
    }

    for (i = 1; i < SIZE; i++) {
        for (j = 2; j < SIZE; j++) {
            apt[i][j] = apt[i-1][j] + apt[i][j-1];
        }

        scanf("%d", &T);

        for (i = 0; i < T; i++) {
            scanf("%d", &k);
            scanf("%d", &n);

            printf("%d\n", apt[k][n]);
        }
    }

    return 0;
}
