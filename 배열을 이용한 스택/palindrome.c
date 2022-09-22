//동덕여대 자료구조
//컴퓨터학과 20191770 이유진
//HW1_1_1
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3
#define MAX_STRING 30
#include <stdio.h>
#include <string.h>


//스택을 위한 타입 정의
typedef char element;

typedef struct {
	element data[MAX_STRING];
	int top;
}StackType;

//스택 초기화 함수
void init(StackType* s) {
	s->top = -1;
}
//공백 상태 검출함수
int is_empty(StackType* s) {
	return s->top == -1;
}
//포화 상태 검출함수
int is_full(StackType* s) {
	return (s->top == MAX_STRING - 1);
}
//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
		return;
	}
}
//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
//피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
//스택 출력 함수
void stack_print(StackType* s) {
	int i;

	if (is_empty(s))
		printf("<empty>\n");
	else {
		for (i = s->top; i >= 0; i--) {
			if (i == s->top)
				printf("%d <- top\n", s->data[i]);
			else
				printf("%d\n", s->data[i]);
		}
	}
	printf("--\n");
}


int palindrome(char str[]) {
	StackType s;

	//필요한 변수들 선언
	int i, j = 0;
	int len = strlen(str);

	//스택을 초기화하라
	init(&s);

	//str의 문자들을 스택에 넣는다
	for (i = 0; i < len; i++)
		push(&s, str[i]);
	s.data[i] = '\0';

	//스택에서 하나씩 빼면서 str의 문자들과 차례로 비교
	for (j = 0; j < len; j++)
		if (pop(&s) != str[j])
			return 0;
	return 1;
}


//main
void main() {
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome 입니다.\n");
	else
		printf("palindrome 이 아닙니다.\n");
}