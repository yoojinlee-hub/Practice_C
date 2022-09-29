#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int makeReverseNum(int n) {
	int reverse = 0, temp = 0;
	while (n > 0) {
		temp = n % 10;
		reverse += temp;
		n /= 10;
	}
	return reverse;
}
int main(void) {
	int a, b;
	char input[200] = " ";

	gets(input);
	a = atoi(strtok(input, " "));
	b = atoi(strtok(NULL, "\0"));

	printf("%d", makeReverseNum(a)+makeReverseNum(b));
}