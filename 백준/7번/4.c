#include <stdio.h>
#include <string.h>

void print(char a[], int b)
{
    int i, j;

    for (i = 0; i < strlen(a); i++) {
        for (j = 0; j < b; j++) {
            printf("%c", a[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, n;
    char p[21] = {0,};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &j);
        scanf("%s", p);
        print(p, j);
    }

    return 0;
}
