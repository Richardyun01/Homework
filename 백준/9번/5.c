#include <stdio.h>

int isPrime(int n)
{
    int i;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main()
{
    int a, cnt = 0;

    scanf("%d", &a);

    if (a == 0) return 0;
    for (int i = a; i <= 2*a; i++) {
        if (isPrime(i) == 1) cnt++;
    }

    printf("%d", &cnt);

    return 0;
}
