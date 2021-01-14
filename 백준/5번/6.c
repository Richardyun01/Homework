#include <stdio.h>
#include <string.h>

#define SIZE 80

int main()
{
    int num, sum = 0, add = 1;
    char arr[SIZE] = {0,};
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%s", arr);
        for (int j = 0; j < strlen(arr); j++) {
            if (arr[j] = 'O') {
                sum += add;
                add++;
            } else {
                add = 1;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
