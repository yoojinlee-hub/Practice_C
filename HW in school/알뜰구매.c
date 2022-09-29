/*************************
20191770 이유진 컴퓨터학과 3학년
https://enter.tistory.com/68 이거보고함
!!!!!!!!!!!!복습필요!!!!!!!!!!!!
*************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main(void) {
	int money, bread = 0, cookie = 0, coke = 0;

	printf("Enter 금액:");
	scanf("%d", &money);
	
	for(bread=500;bread<money;bread+=500)
	for(cookie=700;cookie<money;cookie+=700)
	for(coke=400;coke<money;coke+=400)

		if (bread + cookie + coke == money) {
			printf("빵: %d 쿠키: %d 콜라: %d\n", bread / 500, cookie / 700, coke / 400);
		}
		else
			continue;

	return 0;
}