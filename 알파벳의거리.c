#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int findDistance(char arr[5]) {
	int i, j, sum = 0;

	for (i = 0; i<1; i++)
		for (j = i + 1; arr[j] != '\0'; j++)
			sum += arr[j]-arr[i];
	
	return sum;
}
int main(void) {
	char A[5], B[5];
	int sum = 0, temp = 0;
	scanf("%s %s", A, B);

	sum = findDistance(A) + findDistance(B);
	temp = A[3] - B[0];

	printf("%d", sum);
}