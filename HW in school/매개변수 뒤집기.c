
/*
매개변수 n을 뒤집은 수를 반환하는 함수 solution을 정의하라.

즉 n이 128이면 821을 반환한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int cnt = 0, i, tens = 1, temp = n;

    for (i = temp; temp > 0;) {
        temp /= 10;
        cnt++;
    }
    for (i = 0; i < cnt - 1; i++)
        tens *= 10;
    while (n > 0) {
        answer += (n % 10)*tens;
        n /= 10;
        tens /= 10;
   }
    return answer;
}
int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d\n", solution(n));
}