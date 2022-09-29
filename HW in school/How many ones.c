//How many ones
//20191770 ¿Ã¿Ø¡¯
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countOnes(int n) {
	int count = 0;
	while (n > 0) {
		if (n % 10 != 1) return 0;
		else {
			n /= 10;
			count++;
		}
	}
	return count;
}
int main(void) {
	int A, newNum;
	int i = 1, count;
	scanf("%d", &A);

	count = countOnes(A);
	//if (count != 0) printf("%d", count);
	while (!count) {
		newNum = A * i;
		i += 1;
		count = countOnes(newNum);
	}
	printf("%d\n", count);
}