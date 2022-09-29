//carry¹®Á¦ Àç±Í
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countOperators(int numA, int numB) {
	//int count = 0;
	int a, b;
	if (numA <= 0 || numB <= 0) return 0;
	else {
		a = numA % 10;
		b = numB % 10;
		if (a + b > 9)
			return countOperators(numA / 10 + 1, numB / 10) + 1;
		else
			return countOperators(numA / 10, numB / 10);
	}

}
int main(void) {
	int numA, numB;

	scanf("%d %d", &numA, &numB);

	printf("%d\n", countOperators(numA, numB));
}