#include <stdio.h>

int main()
{
    int N, num, max = -1000001, min = 1000001;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num > max) max = num;
        if (num < min) min = num;
    }

    printf("%d %d\n", max, min);

    return 0;
}
