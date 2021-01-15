#include <stdio.h>

void arr(int **a, int m, int n);
void add(int **a, int **b, int m, int n);
void sub(int **a, int **b, int m, int n);
void mul(int **a, int **b, int m, int n);

void main()
{
    int i, j, select;
    int m, n;

    printf("�� ����� ũ�� �Է�: ");
    scanf("%d%d", &m, &n);

    int a[m][n] = {0,}, b[m][n] = {0,};

    printf("A ��� �Է�\n");

    while (1) {
        for (i = 0; i < m; i++) {
            printf("%d ��: \n", i+1);
            for (j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("A ����� ������ �����ϴ�. \n");
        arr(a, m, n);

        break;
    }

    printf("\n\n");

    printf("B ��� �Է�\n");

    while (1) {
        for (i = 0; i < m; i++) {
            printf("%d ��: \n", i+1);
            for (j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        printf("B ����� ������ �����ϴ�. \n");
        arr(b, m, n);

        break;
    }

    printf("\n\n");
    printf("���� �� ���� ����: 1+ 2- 3*");
    scanf("%d", &select);

    if (select == 1) add(a, b, m, n);
    else if (select == 2) sub(a, b, m, n);
    else if (select == 3) mul(a, b, m, n);
}

void arr(int **a, int m, int n)
{
    int **c;
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

void add(int **a, int **b, int m, int n)
{
    int **c;
    int i, j;
    int m1 = m, n1 = n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    arr(c, m1, n1);
}

void sub(int **a, int **b, int m, int n)
{
    int **c;
    int i, j;
    int m1 = m, n1 = n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    arr(c, m1, n1);
}

void mul(int **a, int **b, int m, int n)
{
    int **c;
    int i, j;
    int m1 = m, n1 = n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    arr(c, m1, n1);
}
