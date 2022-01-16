#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int i;

	 while(1){
		 printf("2부터 9사이 숫자를 입력해주세요(1을 누르면 프로그램이 종료됩니다): ");
		 scanf("%d", &n);

		if (n == 1) {
			 printf("\n프로그램을 종료합니다\n");
			 break;
		 }
		if (n < 2 || n>9) {
			printf("\n범위 외의 숫자입니다\n\n");
			continue;
		}
			 
		 for (i = 1; i <= 9; i++)
			 printf("%d * %d = %d\n", n, i, n * i);
		 printf("\n");
	 }

}