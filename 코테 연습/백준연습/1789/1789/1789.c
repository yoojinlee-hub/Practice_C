#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?
int main(void) {
    long long int S;
    long long int i, sum = 0;
    int N = 0;

    scanf("%lld", &S);

    for (i = 1; ; i++) {
        sum += i; //1부터 더해나가야 최댓값
        N++;
        if (sum >= S) //=가 없어야 답이다 . 이유는 ?
            break;
    }
    
    printf("%d\n", N-1);

    return 0;
}