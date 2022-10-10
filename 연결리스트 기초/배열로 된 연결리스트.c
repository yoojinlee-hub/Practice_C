//20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 5 // 리스트의 최대크기

typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char* message)
{
	printf("%s\n", message);

}
// 리스트 초기화 함수
void init(ArrayListType* L)
{
	L->size = 0;
}
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("리스트끝\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos>=0)&&(pos<=L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
			L->array[pos] = item;
			L->size++;
	}
	if (is_full(L))
		printf("리스트 오버플로우\n");
}
element delete(ArrayListType* L, int pos)
{
	element item;
		if (pos<0||pos>=L->size)
			error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

/// 과제

void clear(ArrayListType* L) {
	for (int i = 0; i <= L->size; i++)
		L->array[i] = NULL;
	L->size = NULL;
}
void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}
int get_length(ArrayListType* L) {
	return L->size;
}
void replace(ArrayListType* L, int pos, element item) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	L->array[pos] = item;
}
int is_in_list(ArrayListType* L, element item) {
	for (int i = 0; i < (L->size - 1); i++)
		if (L->array[i] == item)
			return 1;
	return 0;
}
void delete_by_key(ArrayListType* L, element key) {
	int index = 0;
	if (is_in_list(L, key)) {
		for (int i = 0; i < (L->size - 1); i++)
			if (L->array[i] == key)
				index = i;
		delete(L, index);
	}
	else
		printf("삭제하려는 key값 %d은 리스트에 없습니다\n", key);
	
}
int main(void)
{
	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);
	clear(&list1); print_list(&list1);

	insert_last(&list1, 90); print_list(&list1);

	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10); print_list(&list1);

	delete(&list1, 2); print_list(&list1);

	printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
	insert_first(&list1, 9); print_list(&list1);
	insert_last(&list1, 99); print_list(&list1);

	// 현재 리스트가 꽉 찬(크기 5개) 상태이므로 한 항목을 더 추가하면 "리스트 오버플로우"을 출력한다. 
	insert_first(&list1, 1); print_list(&list1);
	printf("길이는 %d\n", get_length(&list1));

	printf("3번째 데이타는 %d\n", get_entry(&list1, 2));
	replace(&list1, 3, 40); print_list(&list1);

	printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");
	printf("22는 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");

	delete_by_key(&list1, 20); print_list(&list1);
	delete_by_key(&list1, 22); print_list(&list1);
}