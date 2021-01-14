#include <stdio.h>
#include <math.h>

#define SIZE 10000

int arr[SIZE] = {0,};
int SN();

int main() {
    SN();
    return 0;
}

int SN()
{
    int i, j, sum;

    for (i = 0; i < SIZE; i++) {
        sum = 0;
        for (j = 0; j < 5; j++) {
            sum += (i+1/(int)pow(10, j))%10;
        }
        arr[i+sum] = 1;
    }

    for (i = 0; i < SIZE; i++) {
        if (arr[i] == 0) printf("%d\n", i+1);
    }

    return 0;
}
