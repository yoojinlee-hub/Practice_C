#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int num, one = 1, count = 0;
	int remainder = -1;

	scanf("%d", &num);

	count += 1;
	while (remainder != 0) {
		one = one * 10 + 1;
		count++;
		remainder = one % num;
	}
	//printf("%d %d\n", one, one / num); // 1110 370이라고 나옴.
	printf("%d\n", count); //1의 개수
}