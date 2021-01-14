#include <stdio.h>

#define MAX_NUM 100

int main()
{
    int arr[MAX_NUM];
    int cnt[26] = {0,};
    int i, j;
    scanf("%s", arr);

    for (i = 'a'; i < 'z'; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            if (arr[j] == i) {
                cnt[i - 97] = j + 1;
                break;
            }
        }
    }

    for (i = 0; i < 26; i++) printf("%d ", cnt[i] - 1);
    printf("\n");

    return 0;
}
