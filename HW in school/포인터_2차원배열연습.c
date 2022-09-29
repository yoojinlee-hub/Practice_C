
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void generateData();
void printData();
int totalData();
int maxData();
int data[10]; //계산 수행에 사용할 전역 변수

int main(void) {
	srand(200);
	generateData();

	printf("발생된 10개의 난수:\n");
	printData();

	printf("10개 난수의 합 = %d\n", totalData());
	printf("10개 난수중 가장 큰 수 =%d\n", maxData());
}
//generateData함수는 data[0]-[9]에 난수를 넣는다
void generateData() {
	int k;
	int* p;
	p = data; // 혹은 p = &data[0]
	for (k = 0; k < 10; k++) {//Index 0..9까지 난수 부여
		*p = rand() % 100;
		p++;
	}
}
//printData 함수는 data[0]에서 data[9]의 값 출력
void printData() {
	int* pi = data;
	int i;

	for (i = 0; i < 10; i++)
		printf("%d ", *pi++);
	printf("\n");
}
//totalData는 값을 모두 더해 그 결과를 반환한다
int totalData() {
	int* pi = data, sum = 0;
	int i;

	for (i = 0; i < 10; i++)
		sum += *pi++;

	return sum;
}
int maxData() {
	int* p = data, max = *p;
	int i;

	for (i = 0; i < 10; i++) {
		if (*p >= max)
			max = *p;
		p++;
	}
	return max;
}
