#include <stdio.h>

int main()
{
    int H1, M1;
    scanf("%d%d", &H1, &M1);
    int H2;
    if (H1 == 0) H2 = 23;
    else if (H1 != 0) H2 = H1 - 1;

    int M2;
    if (M1 > 45) {
        M2 = M1 + 45;
    } else if (M1 <= 45) {
        M2 = M1 + 15;
    }

    printf("%d\n%d", H2, M2);

    return 0;
}
