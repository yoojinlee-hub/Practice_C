/*****************
* HW4_4 이유진 20191770 컴퓨터학과 2학년
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int comb(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void) {
	int n, r;

	printf("Enter n and r:");
	scanf("%d %d", &n, &r);
	printf("%d", comb(n, r));
	return 0;
}