#include <stdio.h>

#define SIZE 20000

int main()
{
    int i, N, idx = 0;
    int num[SIZE] = {0,};

    num[idx++] = 1;
    while (1) {
        num[idx] = num[idx-1] + 6 + idx;

        if (num[idx] > 10000000) break;

        idx++;
    }

    scanf("%d", &N);

    for (i = 0; i < SIZE; i++) {
        if (num[i-1] < N && N <= num[i]) {
            printf("%d\n", i+1);
            break;
        } else if (num[0] == N) {
            printf("\n");
            break;
        }
    }

    return 0;
}
