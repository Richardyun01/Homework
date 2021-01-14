#include <stdio.h>
#include <string.h>

#define MAX 1000000

int main()
{
    int cnt = 0, mcnt = 0;
    char c[MAX] = {0,}, ma;

    scanf("%c", c);

    for(int i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < strlen(c); j++) {
            if (c[j] == i || c[j] == i - 32) cnt++;
        }

        if (mcnt < cnt) {
            mcnt = cnt;
            ma = i;
            if (ma >= 97) ma -= 32;
        } else if (mcnt == cnt) ma = '?';

        cnt = 0;
    }
    printf("%c", ma);

    return 0;
}
