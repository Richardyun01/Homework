#include <stdio.h>

int main()
{
    int A, B, C, result;
    int num[10] = {0,};
    int count;
    scanf("%d%d%d", &A, &B, &C);

    result = A*B*C;

    while (result > 0) {
        count = result % 10;
        result = result / 10;
        num[count]++;
    }

    for (int i = 0; i < 10; i++) printf("%d\n", num[i]);

    return 0;
}
