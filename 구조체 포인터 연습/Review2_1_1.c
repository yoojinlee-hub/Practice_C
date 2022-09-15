//자료구조 1분반 
//동덕여대 컴퓨터학과 20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int mid;
	int final;
}Score;
void printScore(Score* p) {
	printf("중간고사 성적은 %d\n", p->mid);
	printf("학기말고사 성적은 %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) {
	int sum1 = 0, sum2 = 0;

	sum1 += p1->mid;
	sum1 += p1->final;

	sum2 += p2->mid;
	sum2 += p2->final;

	if (sum1 >= sum2) return p1;
	else return p2;
}
Score* totalScore(Score* p1, Score* p2) {
	int midSum = 0, finalSum = 0;
	Score* returnScore = (Score*)malloc(sizeof(Score));

	midSum = p1->mid + p2->mid;
	finalSum = p1->final + p2->final;

	returnScore->mid = midSum;
	returnScore->final = finalSum;

	return returnScore;
}
Score* createScore(int m, int f) {
	Score* returnScore = (Score*)malloc(sizeof(Score));
	returnScore->mid = m;
	returnScore->final = f;
	return returnScore;
}
int main(void) {
	Score* p1, * p2, * p3;

	//1) p1,p2에 score를 저장하기 위한 메모리를 할당하고 값을 대입한다
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	p1->mid = 50; p1->final = 100;
	p2->mid = 70; p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));

	printf("------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));

	printf("------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}