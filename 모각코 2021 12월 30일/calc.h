#ifndef HEADER
#define HEADER
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int answer(char s, int a, int b) {
	if (s == '+')
		return a + b;
	else if (s == '-')
		return a - b;
	else if (s == '*')
		return a * b;
	else if (s == '/') {
		if (b == 0)
			return -100000;
		else
			return a / b;
	}
	else
		return -100000;
}

#endif // !HEADER