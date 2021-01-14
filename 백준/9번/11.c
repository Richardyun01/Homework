#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    int x1, y1, r1, x2, y2, r2;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

        if (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) > r2-r1) {
            printf("2\n");
        } else if (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) == r2-r1 || sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) == r2+r1) {
            printf("1\n");
        } else if (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) < r2-r1) {
            printf("0\n");
        }
    }

    return 0;
}
