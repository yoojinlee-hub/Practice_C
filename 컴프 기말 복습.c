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
    int threes = 3, tens = 1, jarisu = 0;
    int i, j = 0, k;
    int nums[100000] = { 0 };
    int mul3[100000] = { 0 };

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        nums[i] = i + 1;

    for (i = 0; i < n; i++) {
        threes = 3 * nums[i];
        jarisu = solution(threes);
        if (jarisu > 1) {
            while (jarisu > 1) {
                tens = 1;
                for (k = 1; k < jarisu; k++) {
                    tens *= 10;
                }
                mul3[j] = threes / tens;
                threes = threes % tens;
                j++;
                jarisu--;
            }
            mul3[j] = threes;
        }
        else
            mul3[j] = threes;
        j++;
    }
    printf("%d\n", mul3[n + 1]);
}