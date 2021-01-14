#include <stdio.h>

int main()
{
    int num[42] = {0,};
    int i, N, count=0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &N);
        num[N%42]++;
    }
    for (i = 0; i < 42; i++) {
        if (num[i] != 0) count++;
    }

    printf("%d", count);

    return 0;
}
