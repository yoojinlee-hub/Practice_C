#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[20];
	int age;
	int grade;
	int math;
	int eng;
	int kor;
	int avg;
}Student;
int main(void) {
	Student s1;

	//입력
	printf("이름 : ");
	scanf("%s", s1.name);
	printf("나이 : ");
	scanf("%d", &s1.age);
	printf("학년 : ");
	scanf("%d", &s1.grade);
	printf("수학 : ");
	scanf("%d", &s1.math);
	printf("영어 : ");
	scanf("%d", &s1.eng);
	printf("국어 : ");
	scanf("%d", &s1.kor);

	s1.avg = (s1.math + s1.kor + s1.eng) / 3;
	//출력
	printf("[학생]\n");
	printf("이름 : %s\n", s1.name);
	printf("나이 : %d\n", s1.age);
	printf("학년 : %d\n", s1.grade);
	printf("수학 : %d\n", s1.math);
	printf("영어 : %d\n", s1.eng);
	printf("국어 : %d\n", s1.kor);
	printf("평균점수 : %d\n", s1.avg);
}