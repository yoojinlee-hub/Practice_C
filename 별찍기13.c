#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num, i, j;

    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    for (i = num - 2; i >= 0; i--) {
        for (j = i; j >=0; j--)
            printf("*");
        printf("\n");
    }
}