#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char str[MAX] = {0,};
    int cnt = 0;

    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'c') {
            if (str[i+1] == '=') {
                i++;
            } else if (str[i+1] == '-') {
                i++;
            }
        } else if (str[i] == 'd') {
            if (str[i+1] == 'z') {
                if (str[i+2] == '=') {
                    i+=2;
                }
            } else if (str[i+1] == '-') {
                i++;
            }
        } else if (str[i] == 'l') {
            if (str[i+1] == 'j') {
                i++;
            }
        } else if (str[i] == 'n') {
            if (str[i+1] == 'j') {
                i++;
            }
        } else if (str[i] == 's') {
            if (str[i+1] == '=') {
                i++;
            }
        } else if (str[i] == 'z') {
            if (str[i+1] == '=') {
                i++;
            }
        }
        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
