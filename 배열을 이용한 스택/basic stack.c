//동덕여대 자료구조
//컴퓨터학과 20191770 이유진
//HW1_1_1
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3
#include <stdio.h>

//스택을 위한 타입 정의
typedef int element;

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
//main
void main() {
	StackType s;

	init(&s);
	stack_print(&s);

	push(&s, 10);
	stack_print(&s);

	push(&s, 20);
	stack_print(&s);

	push(&s, 30);
	stack_print(&s);

	push(&s, 40);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	push(&s, 50);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}