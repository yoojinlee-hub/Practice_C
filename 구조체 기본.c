
#include <stdio.h>
#include <stdlib.h>

// 1) typedef으로 구조체 타입 Score 정의하라.
typedef struct {
	int midterm;
	int final;
}Score;

void printScore(Score s) //2)
{
	printf("중간고사 성적은 %d\n", s.midterm);
	printf("학기말고사 성적은 %d\n", s.final);
}
Score biggerScore(Score s1, Score s2) //3)
{
	if (s1.midterm + s1.final >= s1.midterm + s1.final)
		return s1;
	else
		return s2;
}
Score totalScore(Score s1, Score s2) //4)
{
	Score total;
	total.midterm = s1.midterm  + s2.midterm ;
	total.final = s1.final + s2.final;
	return total;
}
Score createScore(int m, int f) //5)
{
	Score newScore;
	newScore.midterm = m;
	newScore.final = f;
	return newScore;
}
int main(void) {
	Score s1, s2, s3;
	s1.midterm = 50; s1.final = 100;
	s2.midterm = 70; s2.final = 70;

	printf("1)-----------------------------\n");
	printScore(s1);
	printScore(s2);

	printf("2)-----------------------------\n");
	printf("둘 중 성적이 좋은 점수:\n");
	printScore(biggerScore(s1, s2));

	printf("3)-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(s1, s2));

	printf("4)-----------------------------\n");
	s3 = createScore(99, 99);
	printScore(s3);
}
