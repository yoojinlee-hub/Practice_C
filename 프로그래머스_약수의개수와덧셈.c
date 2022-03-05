#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int howManyMeasure(int n) {
    int count = 0;
    int i;
    for (i = 1; i <= n; i++)
        if (n % i == 0)
            count++;
    return count;
}
int solution(int left, int right) {
    int answer = 0;
    int i;
    for (i = left; i <= right; i++)
        if (howManyMeasure(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    return answer;
}
int main(void) {

}