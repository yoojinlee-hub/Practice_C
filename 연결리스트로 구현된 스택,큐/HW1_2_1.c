//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;


// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType* s) //꽉 차있을 때는 없음
{
	return 0;
}

// 삽입 함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}

// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		return;
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// 피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		return;
	}
	else {
		return s->top->data;
	}
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//스택 출력 함수
void stack_print(LinkedStackType* s) {
	StackNode* temp = s->top;

	if (is_empty(s))
		printf("(empty)\n");
	else {
		while(temp!=NULL) {
			if (temp == s->top) 
				printf("%d <- top\n", s->top->data);
			else 
				printf("%d\n", temp->data);
			temp = temp->link;
		}
	}
	printf("--\n");
}

//main
void main() {
	LinkedStackType* s;

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

	pop(&s);
	stack_print(&s);
}