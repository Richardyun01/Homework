#include <stdio.h>

int main()
{
    int N, a;
    int num = 0, count = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a);

        for (int j = 2; j <= a; j++) {
            if (a % j == 0) {
                count++;
            }
            if (count == 2) {
                num++;
            }
        }
    }

    printf("%d", num);

    return 0;
}
