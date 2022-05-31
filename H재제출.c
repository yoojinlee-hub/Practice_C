#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long H(int n, long long* M)
{
	int i;
	long long result = 0;
	if (n == 1)
		return 1;
	for (i = 1; i < n; i++) {
		if (M[n - 1 - i] == 0)
			M[n - 1 - i] = H(n - 1 - i, M);

		result += M[n - 1 - i] * i;
	}
	return result;
}
int main(void)
{
	int n, i;
	long long* M; //Memo

	scanf("%d", &n);
	M = (long long*)malloc(sizeof(long long) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;

	printf("%lld\n", H(n, M));
}