#include "calc.h"

int main(void) {
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("%d %c %d = %d\n", a, '+', b, answer('+', a, b));
	printf("%d %c %d = %d\n", a, '-', b, answer('-', a, b));
	printf("%d %c %d = %d\n", a, '*', b, answer('*', a, b));
	printf("%d %c %d = %d\n", a, '/', b, answer('/', a, b));

	return 0;
}