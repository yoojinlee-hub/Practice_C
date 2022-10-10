#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	printf("%s\n", message);
}

ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; //(2)
	p->link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; //
	head = p;

	return head;
}
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	p->link = NULL;
	// (2)

	if (head == NULL)
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) error("삭제할 것이 없음");
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;
	ListNode* removed;
	if (head == NULL) error("삭제할 것이 없음");
	if (temp->link == NULL) {
		removed = temp->link;
		temp->link = NULL;
		free(removed);
		return NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
		free(removed);
		return head;
	}
}
void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
ListNode* search(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head)
{
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트.
		// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; // q의 링크 방향을 바꾼다.
	}
	return q;
}

int is_in_list(ListNode* head, element item)
{
	ListNode* temp = head;
	while (temp != NULL) {
		if (temp->data == item) return 1;
		temp = temp->link;
	}
	return 0;
}

int get_length(ListNode* head)
{
	ListNode* temp = head;
	int len = 0;
	while (temp != NULL) {
		len++;
		temp = temp->link;
	}
	return len;
}

ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;

	if (head->data == key)
		head = delete_first(head);
	else {
		while (temp != NULL) {
			if (temp->data == key) {
				prevTemp->link = temp->link;
				temp->link = NULL;
				free(temp);
				return head;
			}
			prevTemp = temp;
			temp = temp->link;
		}
		printf("해당 key를 가진 노드가 없어 삭제가 불가능합니다.\n");
	}
	return head;
}