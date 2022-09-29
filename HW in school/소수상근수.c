#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isitPrime(int n) {
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
int findit(int n) {
	//아닐때: 20 -> 4 로 끝나는걸 반복함
	int sum = 0;
	int i = 0;

	if (n == 4) return 0;

	while (n > 0) {
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	if (sum == 1)return 1;
	else if (sum != 1) return findit(sum);

}
int main(void) {
	int n;
	int i, j = 0;

	scanf("%d", &n);

	for (i = 2; i <= n; i++)
		if (findit(i) == 1 && isitPrime(i))
			printf("%d\n", i);

}