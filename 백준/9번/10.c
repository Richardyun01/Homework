#include <stdio.h>

int main()
{
    int r;
    scanf("%d", &r);

    printf("%.6f\n", (float)r * 3.141593);
    printf("%.6f\n", (float)r * (float)r * 2);

    return 0;
}
