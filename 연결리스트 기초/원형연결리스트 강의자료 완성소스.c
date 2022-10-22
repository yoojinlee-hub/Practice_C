//20191770 이유진
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { 
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) 
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->리스트의 끝", p->data); 
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data) 
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* temp;
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
			return NULL;
	}
	else if (head == head->link) {  //원소 하나
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* p;
	ListNode* removed;
	p = head->link;

	if (head == NULL) {
		printf("리스트가 비어있어 삭제를 못함");
		return head;
	}
	
	while (p->link != head) {  //맨 뒤까지 찾기
		p = p->link; //뒤로 이동
	}
	removed = head;
	p->link = removed->link;
	head = p;
	return head;
}
ListNode* search(ListNode* head, element data)
{
	ListNode* p;
	p = head;
	if (head == NULL) return;
	 do{  //맨 뒤까지 찾기
		if (p->data == data)
			return p;
		p = p->link; //뒤로 이동
	}while (p != head);
	return p;
}
int get_size(ListNode* head)
{
	ListNode* p;
	p = head;
	int size = 0;
	do {  //맨 뒤까지 찾기
		size += 1;
		p = p->link; //뒤로 이동
	} while (p != head);
	return size;
}

int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40


	head = insert_last(head, 20);
	print_list(head); //20
	head = insert_last(head, 30);
	print_list(head); //20->30
	head = insert_last(head, 40);
	print_list(head); //20->30->40
	head = insert_first(head, 10);
	print_list(head); //10->20->30->40
	head = delete_first(head);
	print_list(head); //20->30->40

	/*test*/
	head = delete_last(head);
	print_list(head); //20->30

	return 0;
}