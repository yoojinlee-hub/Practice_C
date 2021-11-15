#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n = 0;
	int x, y;
	int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;

	scanf("%d", &n);

	while(n!=0) {
		scanf("%d", &x);
		scanf("%d", &y);

		if (x == 0 || y == 0)
			AXIS++;
		else if (x > 0 && y > 0)
			Q1++;
		else if (x > 0 && y < 0)
			Q4++;
		else if (x < 0 && y>0)
			Q2++;
		else if (x < 0 && y < 0)
			Q3++;
		n--;
	}
	printf("Q1: %d\n", Q1);
	printf("Q2: %d\n", Q2);
	printf("Q3: %d\n", Q3);
	printf("Q4: %d\n", Q4);
	printf("AXIS: %d\n", AXIS);
}