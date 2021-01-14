#include <stdio.h>

#define MAX_NUM 10001

int sum(int n)
{
    int sum = n;

    while (n > 0) {
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int arr[MAX_NUM] = {0,};
    int i, check;

    for (i = 1; i < MAX_NUM; i++) {
        check = sum(i);
        if (check < MAX_NUM) arr[check] = 1;
        if (arr[i] != 1) printf("%d\n", i);
    }

    return 0;
}
