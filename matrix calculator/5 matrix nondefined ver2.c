#include <stdio.h>

void input1(int n, int m, int a[10][10]);
void input2(int n, int m, int b[10][10]);
void addArray(int n, int m, int a[10][10], int b[10][10], int c[10][10]);
void subArray(int n, int m, int a[10][10], int b[10][10], int c[10][10]);
void mulArray(int n, int m, int p, int q, int a[10][10], int b[10][10], int c[10][10]);
//void selection(int n, int m, int p, int q, int a[10][10], int b[10][10]);

int main()
{
    int a[10][10], b[10][10], c[10][10] = {0,};
    int i, j, k, n, m, p, q;
    int sum = 0;

    printf("Enter row of 1st matrix: ");
    scanf("%d", &n);

    printf("Enter column of 1st matrix: ");
    scanf("%d", &m);

    input1(n, m, a);


    printf("Enter row of 2st matrix: ");
    scanf("%d", &p);

    printf("Enter column of 2st matrix: ");
    scanf("%d", &q);

    input2(p, q, b);


    printf("\n\n");

    int select;

    printf("다음 중 행할 연산: 1+ 2- 3*: \n");
    scanf("%d", &select);

    if (select == 1) {
        if (n == p && m == q) {
            addArray(n, m, a, b, c);
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 2) {
        if (n == p && m == q) {
            subArray(n, m, a, b, c);
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 3) {
        mulArray(n, m, p, q, a, b, c);
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////

void input1(int n, int m, int a[10][10])
{
    int i, j;

    printf("Enter the matrix A: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void input2(int n, int m, int b[10][10])
{
    int i, j;

    printf("Enter the matrix B: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
}

/*void selection(int n, int m, int p, int q, int a[][], int b[][])
{
    int select;

    printf("다음 중 행할 연산: 1+ 2- 3*: \n");
    scanf("%d", &select);

    if (select == 1) {
        if (n == p && m == q) {
            addArray(n, m, a[10][10], b[10][10]);
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 2) {
        if (n == p && m == q) {
            subArray(n, m, a[10][10], b[10][10]);
        } else {
            printf("계산 불가\n");
        }
    } else if (select == 3) {
        mulArray(n, m, p, q, a[10][10], b[10][10]);
    }
}*/

/////////////////////////////////////////////////////////////////////////////////////////////////

void addArray(int n, int m, int a[10][10], int b[10][10], int c[10][10])
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void subArray(int n, int m, int a[10][10], int b[10][10], int c[10][10])
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = a[i][j] - b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void mulArray(int n, int m, int p, int q, int a[10][10], int b[10][10], int c[10][10])
{
    int i, j, k;
    int sum = 0;

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
