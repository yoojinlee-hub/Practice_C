#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
0 이상 99이하의 정수를 입력 받고, 각 자릿수의 합을 구합니다.
9 이하의 수는 그대로 사용합니다.
입력 받은 수의 가장 오른쪽 자릿수와 앞에서 구한 합의 가장 오른쪽 자릿수를 이어 붙여 새로운 수를 생성 합니다.
새로운 수로 1, 2를 반복하여 본래의 숫자로 돌아갈 때 까지 몇 번의 과정을 거쳐야 하는지 계산하는 프로그램을 작성해보세요.
*/
int makeNewNum(int n) {
	int sum = 0, temp = n;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	sum = sum % 10;
	sum += (temp % 10) * 10;
	return sum;
}
int main(void) {
	int n, temp, count = 0;
	int newNum = 0;

	scanf("%d", &n);

	temp = n;
	do{
		newNum = makeNewNum(n);
		n = newNum;
		count++;
	}while (newNum != temp);

	printf("%d", count);
}