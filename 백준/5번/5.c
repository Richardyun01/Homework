#include <stdio.h>

#define NUM 256

int main()
{
    int N, max = 0;
    int score[NUM] = {0,};
    double newScore[NUM] = {0,};
    double sum = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
        if (score[i] > max) max = score[i];
    }

    for (int i = 0; i < N; i++) {
        newScore[i] = (double)score[i] / (double)max * 100;
        sum += newScore[i];
    }

    printf("%.4lf\n", (double)(sum/N));

    return 0;
}
