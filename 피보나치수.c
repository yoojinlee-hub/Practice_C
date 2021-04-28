#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, i=0,f,f1,nextTerm;

	scanf("%d", &n);

	f = 0;
	f1 = 1;
	if (n == 0) 
		printf("0\n");
	else if (n == 1) 
		printf("1\n");
	else {
		for (i = 1; i <= n; i++) {
			nextTerm = f1 + f;
			f = f1;
			f1 = nextTerm;

			if (i == n - 1) {
				printf("%d\n", nextTerm);
			}
		}
	}
	
	return 0;
}