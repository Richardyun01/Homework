#include <stdio.h>

int main()
{
    int M, N;
    int first = 0, min = 0, sum = 0;

    scanf("%d%d", &M, &N);

    for (int i = N; i <= M; i++) {
        for (int j = 2; j <= i; j++) {
            if (i % j == 0) {
                if (i == j) {
                    sum += i;
                    first++;
                    if (first == 1) min == i;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    if (sum == 0) printf("-1\n");
    else printf("%d\n%d", sum, min);

    return 0;
}
