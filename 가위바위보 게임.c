#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int computerAnswer() {
	int random = rand() % 3 + 1; //1,2,3
	return random;
}
void whatIs(int n) {
	if (n == 1) printf("가위");
	if (n == 2) printf("바위");
	if (n == 3) printf("보");
}
int main(void) {
	int input, com = 0;

	printf("**************** 가위 바위 보 게임 ****************\n");
	printf("1. 가위 2. 바위 3. 보 \n입력해주세요 :");
	scanf("%d", &input);

	srand(time(NULL));
	com = computerAnswer();//1. 가위 2. 바위 3. 보

	printf("\n컴퓨터:");
	whatIs(com);
	printf("\n사용자:");
	whatIs(input);

	if (com == input) printf("\n비겼습니다.\n");
	else if (com == input + 1 || (input == 3 && com == 1)) printf("\n졌습니다ㅠㅠ\n");
	else printf("\n이겼습니다!\n");
}