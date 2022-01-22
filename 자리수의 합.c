#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int findJarisu(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(void) {
	int input[5], maxIndex;
	int jarisu[5], max;
	int i;

	for (i = 0; i < 5; i++) {
		scanf("%d", &input[i]);
		jarisu[i] = findJarisu(input[i]);
	}

	max = jarisu[0];
	for (i = 0; i < 5; i++) {
		if (max <= jarisu[i])
			maxIndex = i;
	}

	printf("%d\n", input[maxIndex]);
}