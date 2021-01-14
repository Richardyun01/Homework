#include <stdio.h>

#define NUM 100

int main()
{
    int N1, N2;
    int score[NUM] = {0,};
    int sum = 0;
    scanf("%d", N1);

    for (int i = 0; i < N1; i++) {
        scanf("%d", N2);
        for (int j = 0; j < N2; j++) {
            scanf("%d", score[j]);

            sum += score[j];
        }
        printf("%.3f%\n", (float)(sum / N2));
    }

    return 0;
}
