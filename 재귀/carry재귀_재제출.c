#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_carry(int numA, int numB, int carry) {
	int a, b;
	if (numA <= 0 || numB <= 0) return carry;
	else {
		a = numA % 10;
		b = numB % 10;
		if (a + b > 9)
			return get_carry(numA / 10 + 1, numB / 10, ++carry);
		else
			return get_carry(numA / 10, numB / 10, carry);
	}

}
int main(void) {
	int numA, numB;

	scanf("%d %d", &numA, &numB);

	printf("%d\n", get_carry(numA, numB, 0));
}