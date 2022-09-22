//동덕여대 자료구조
//컴퓨터학과 20191770 이유진
//HW1_1_2
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3
#include <stdio.h>

//스택을 위한 타입 정의
typedef struct {
	int value;
	char name[20];
}element;

typedef struct {
	element data[MAX_STACK_SIZE];
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
	return s->top == MAX_STACK_SIZE - 1;
}
//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}
//삭제함수
element pop(StackType* s) {
	element temp;
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
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
				printf("[%d, %s] <- top\n", s->data[i].value, s->data[i].name);
			else
				printf("[%d, %s]\n", s->data[i].value, s->data[i].name);
		}
	}
	printf("--\n");
}
//main
void main() {
	StackType s;

	init(&s);
	stack_print(&s);

	element e1 = { 10,"ten" };
	push(&s, e1);
	stack_print(&s);
	
	element e2 = { 20, "twenty" };
	push(&s, e2);
	stack_print(&s);

	element e3 = { 30, "thirty" };
	push(&s, e3);
	stack_print(&s);

	element e4 = { 40, "forty" };
	push(&s, e4);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	element e5 = { 50, "fifty" };
	push(&s, e5);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}