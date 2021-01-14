#include <stdio.h>

int main()
{
    int T;
    int A, B, C;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &A, &B);
        C = A + B;
        printf("case #%d: %d + %d = %d\n", i, A, B, C);
    }

    return 0;
}
