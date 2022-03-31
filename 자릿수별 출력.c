//20191770 ¿Ã¿Ø¡¯
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, n9, temp;
	int tens = 1;
	scanf("%d", &n);
	n9 = n * 9;
	temp = n9;
	
	while (temp > 0) {
		temp /= 10;
		tens *= 10;
	}
	tens /= 10;
	while (tens > 0) {
		printf("%d ", n9 / tens);
		n9 %= tens;
		tens /= 10;
	}
}