#include <stdio.h>
#include <string.h>

#define MAX 1000000

int main()
{
    char str[MAX] = {0,};
    int i, sum = 0;

    gets(str);

    for (i = 0; i < strlen(str); i++) {
        if (str[i] != " ") {
            if (i > 0 && str[i-1] != ' ') {
                continue;
            } else {
                sum++;
            }
        }
    }

    printf("%d", sum);

    return 0;
}
