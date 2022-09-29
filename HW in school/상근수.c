#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	int n, arr[100];
	int i, j = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) 
		if (findit(i) == 1) 
			arr[j++] = i;
	
	for (i = 0; i < j; i++) 
		if (i != j - 1) printf("%d,",arr[i]);
		else printf("%d\n", arr[i]);
	
}