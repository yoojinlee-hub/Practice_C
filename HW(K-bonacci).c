//20191770юлю╞аЬ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int four_bonacci(int n) {
	if (n > 4)
		return four_bonacci(n - 1) + four_bonacci(n - 2) + four_bonacci(n - 3) + four_bonacci(n - 4);
	else
		return 1;
}
*/
int K_bonacci(int k, int n) {
	int i, sum = 0;
	if (n > k) {
		for (i = 1; i <= k; i++)
			sum += K_bonacci(k, n - i);
		return sum;
	}
	else
		return 1;
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", K_bonacci(n, m));
}