/*****************
* challenge4_2 이유진 20191770 컴퓨터학과 2학년
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y);
int main(void) {
	int a, b, big, small;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	if (a < b) {
		big = b;
		small = a;
	}
	else {
		big = a;
		small = b;
	}
	printf("%d와 %d의 최대공약수는 %d\n", a, b, gcd(big, small));
}
int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}