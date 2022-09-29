/*****************
* HW4_3_1 이유진 20191770 컴퓨터학과 2학년
*******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int xPower(int x,int y);
int main(void) {
	int x, y;
	printf("Enter two number:");
	scanf("%d %d", &x, &y);

	printf("%d의 %d승은 %d이다\n", x, y, xPower(x, y));
}
int xPower(int x,int y) {
	if (y == 0)
		return 1;
	else
		return x * xPower(x, y - 1);
}