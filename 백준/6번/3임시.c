#include <stdio.h>

#define MAX_NUM 1001

int Han(int n)
{
    int a, b, c, cnt = 0 ;

    if (n < 100) {
        return n;
    } else {
        for (int i = 0; i <= n; i++) {
            a = i / 100;
            b = (i % 100) / 10;
            c = (i % 100) % 10;
            if ((a - b) == (b - c)) cnt++;
        }
        return (99 + cnt);
    }
}

int main()
{
    int input, res;
    scanf("%d", &input);

    res = Han(input);
    printf("%d", res);

    return 0;
}
