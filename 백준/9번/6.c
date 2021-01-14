#include <stdio.h>

int main()
{
    int t, n;
    int a, b;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = n/2; j <= n; j++) {
            for (int k = 2; k < j; k++) {
                a = k;
                if (j % k == 0) a++;
                if (j % k != 0) {
                    b = n - a;
                    break;
                }
            }
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}
