#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//https://kin.naver.com/qna/detail.naver?d1id=1&dirId=104&docId=251516043&qb=7J6s6reA7ZWo7IiYIOyGjOyduOyImOu2hO2VtA==&enc=utf8&section=kin.ext&rank=2&search_sort=0&spq=0
//https://www.acmicpc.net/board/view/58321

void findPrime(int n) {
	int i;
	if (n == 1)
		return;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			break;
	printf("%d\n", i);
	findPrime(n / i);
}
int main(void) {
	int n;

	printf("숫자를 입력해주세요:");
	scanf("%d", &n);

	findPrime(n);
}