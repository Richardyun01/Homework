#include <stdio.h>

int main()
{
    int N, num, count, max = -1000001;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);

        if (N > max) {
            count = i;
            max = num;
        }
    }

    printf("%d\n%d", max, count);

    return 0;
}
