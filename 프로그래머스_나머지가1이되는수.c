#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int i;

    for (i = 1; i < n; i++)
        if (n % i == 1)
            return i;
    return answer;
}
int main(void) {
    solution(10);
}