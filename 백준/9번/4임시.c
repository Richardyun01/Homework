#include <stdio.h>

#define MAX 1000000

int main()
{
    int m, n;
    int cont, cnt = 0;

    scanf("%d%d", &m, &n);

    for (int i = m; i <= n; i++) {
        cont = 0;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                j = 2;
                cont++;
                break;
            }
        }
        if (i == 1) continue;
        if (cont == 0) printf("%d\n", i);
    }

    return 0;
}
