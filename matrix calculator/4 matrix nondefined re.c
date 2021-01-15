#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10] = {0,};
    int i, j, k, n, m, p, q, select;
    int sum = 0;

    printf("Enter row of 1st matrix: ");
    scanf("%d", &n);

    printf("Enter column of 1st matrix: ");
    scanf("%d", &m);

    printf("Enter the matrix A: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter row of 2st matrix: ");
    scanf("%d", &p);

    printf("Enter column of 2st matrix: ");
    scanf("%d", &q);

    printf("Enter the matrix B: \n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n\n");
    printf("다음 중 행할 연산: 1+ 2- 3*: \n");
    scanf("%d", &select);

    if (select == 1) {
        if (n == p && m == q) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 2) {
        if (n == p && m == q) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i][j] = a[i][j] - b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 3) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < q; j++) {
                for (k = 0; k < p; k++) {
                    sum = sum + a[i][k] * b[k][j];
                }
                c[i][j] = sum;
                sum = 0;
            }
        }
        printf("결과\n");

        for (i = 0; i < n; i++) {
            for (j = 0; j < q; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
