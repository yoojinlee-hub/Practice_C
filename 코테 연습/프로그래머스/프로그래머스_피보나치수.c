//시간초과
//https://programmers.co.kr/questions/11991
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fibo(int n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else return (fibo((n - 1) % 1234567)  + fibo((n - 2) % 1234567) ) % 1234567;
}
int solution(int n) { 
    int answer = 0;
    answer = (fibo(n) % 1234567);
    return answer;
}
int main(void) {
    solution(5);
}