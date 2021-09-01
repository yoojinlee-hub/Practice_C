
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int coins[4] = { 500,100,50,10 };
	int coin[4] = { 0 };
	int change;
	int i;

	printf("Enter the amount of change:");
	scanf("%d", &change);

	for (i = 0; i < 4; i++) {
		if (change >= coins[i]) {
			coin[i] = change / coins[i];
			change = change % coins[i];
		}
		printf("%d coin: %d\n", coins[i], coin[i]);
	}
	
}