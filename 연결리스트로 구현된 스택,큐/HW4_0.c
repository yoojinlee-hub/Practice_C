//20191770이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//스택을 위한 타입 정의 
typedef TreeNode* element;

typedef struct {
	TreeNode* top;
} LinkedStackType;

//여기에 연결된 스택 프로그램 함수를 추가 
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
TreeNode* insert_node(TreeNode* root, int key)
{
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (root == NULL) return;
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < root->data)
		root->left = insert_node(root->left, key);
	else if (key > root->data)
		root->right = insert_node(root->right, key);
	// 변경된 루트 포인터를 반환한다.
	return root;
}


// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		return;
	}
	else {
		TreeNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->right;
		free(temp);
		return temp;
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

//스택 출력 함수
void stack_print(LinkedStackType* s) {
	TreeNode* temp = s->top;

	if (is_empty(s))
		printf("(empty)\n");
	else {
		while (temp != NULL) {
			if (temp == s->top)
				printf("%d <- top\n", s->top->data);
			else
				printf("%d\n", temp->data);
			temp = temp->right;
		}
	}
	printf("--\n");
}

void inorder_iter(TreeNode* root)
{
	//여기에 연결된 스택을 이용한 반복적 순회 관련 코드 추가 
	if (root != NULL) {
		inorder_iter(root->left);
		printf("[%d] ", root->data);
		inorder_iter(root->right);
	}
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}