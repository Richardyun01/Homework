#include <stdio.h>

void arr(int a[3][3]);
void add(int a[3][3], int b[3][3]);
void sub(int a[3][3], int b[3][3]);
void mul(int a[3][3], int b[3][3]);

void main()
{
    int a[3][3], b[3][3];
    int i, j, select;

    printf("A ����� �Է��Ͻÿ�\n");

    while (1) {
        for (i = 0; i < 3; i++) {
            printf("%d ��: \n", i+1);
            for (j = 0; j < 3; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        printf("A ����� ������ ����.\n");
        arr(a);
        break;
    }

    //printf("A ����� ������ ����.\n");
    //arr(a);

    printf("\n\n");

    printf("B ����� �Է��Ͻÿ�\n");

    while (1) {
        for (i = 0; i < 3; i++) {
            printf("%d ��: \n", i+1);
            for (j = 0; j < 3; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        printf("B ����� ������ ����.\n");
        arr(b);
        break;
    }

    //printf("B ����� ������ ����.\n");
    //arr(b);

    printf("\n\n");
    printf("���� �� ���� ����: 1+ 2- 3*\n");
    scanf("%d", &select);

    if (select == 1) add(a, b);
    else if (select == 2) sub(a, b);
    else if (select == 3) mul(a, b);
}

void arr(int a[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void add(int a[3][3], int b[3][3])
{
    int c[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    arr(c);
}

void sub(int a[3][3], int b[3][3])
{
    int c[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    arr(c);
}

void mul(int a[3][3], int b[3][3])
{
    int c[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    arr(c);
}
