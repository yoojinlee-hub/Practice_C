// 전체 코드 작성
// 함수를 써도 좋고 안써도 좋다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int solution(int n) // 코드 작성
{
    int jarisu = 0;
    while (n > 0) {
        n /= 10;
        jarisu++;
    }
    return jarisu;
}
int main(void) {
    int n;
    int threes = 3, tens, jarisu = 0;
    int i, j = 0, k;
    scanf("%d", &n);

    int nums[100000] = { 0 };
    for (i = 0; i < n; i++)
        nums[i] = i + 1;

    int mul3[100000] = { 0 };
    for (i = 0; i < n; i++) {
        tens = 1;
        threes = 3 * nums[i];
        jarisu = solution(threes);
        if (jarisu > 1) {
            for (k = 1; k < jarisu; k++) {
                tens *= 10;
            }
            mul3[j] = threes / tens;
            mul3[j+1] = threes % tens;
            j++;
        }
        else
            mul3[j] = threes;
        j++;
    }
    printf("%d", mul3[n+1]);
}