#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_carry(int numA, int numB, int carry) {
    int totalCarry = 0;
    int calNum1, calNum2;

    while (numA > 0 || numB > 0) {
        if (numA % 10 - numB % 10 - carry < 0) {
            totalCarry++;
            carry = 1;
        }
        else
            carry = 0;
        numA /= 10;
        numB /= 10;
    }
    return totalCarry;
}
int main(void) {
    int numA, numB;

    scanf("%d %d", &numA, &numB);

    printf("%d\n", get_carry(numA, numB, 0));
}