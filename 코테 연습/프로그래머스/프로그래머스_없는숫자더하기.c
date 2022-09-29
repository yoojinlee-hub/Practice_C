#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
0부터 9까지의 숫자 중 일부가 들어있는 정수 
배열 numbers가 매개변수로 주어집니다. 
numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 
더한 수를 return 하도록 solution 함수를 완성해주세요.
*/
// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int sum = 0, total = 45;
    int i;
    for (i = 0; i < numbers_len; i++)sum += numbers[i];
    sum = total - sum;
    return sum;
}
int main() {
    int arr[] = { 5,8,4,0,6,7,9 };

    printf("%d",solution(arr, 6));
}