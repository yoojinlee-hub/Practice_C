//How many carry operations

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countOperators(int numA, int numB) {
	int count = 0;
	int a, b;
	while (numA > 0 && numB > 0) {
		a = numA % 10;
		b = numB % 10;
		if (a + b > 9) {
			count++;
			numA = numA / 10 + 1;
			numB = numB / 10;
		}
		else {
			numA = numA / 10;
			numB = numB / 10;
		}
	}
	return count;
}
int main(void) {
	int numA, numB;
	
	scanf("%d %d", &numA, &numB);

	printf("%d\n", countOperators(numA, numB));
}