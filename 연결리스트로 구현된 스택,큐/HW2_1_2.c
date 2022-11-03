//컴퓨터학과 20191770 이유진
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[20];
}element;

typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { 
	QueueNode* front, * rear;
} LinkedQueueType;

// 초기화 함수
void init(LinkedQueueType* q)
{
	q->front = NULL;
	q->rear = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) // 항상 거짓, 포화상태일때가 없다
{
	return 0;
}

// 삽입 함수
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item; // 데이터 저장
		temp->link = NULL; // 링크 필드를 NULL
		if (is_empty(q)) { // 큐가 공백이면
			q->front = temp;
			q->rear = temp;
		}
		else { // 큐가 공백이 아니면
			q->rear->link = temp; // 순서가 중요
			q->rear = temp;
		}
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // 공백상태
		printf("큐가 비어 있읍니다");
	else {
		item = temp->data; // 데이터를 꺼낸다.
		q->front = q->front->link; // front 를 다음노드를 가리키도록 한다.
		if (q->front == NULL) // 공백 상태
			q->rear = NULL;
		free(temp); // 동적메모리 해제
		return item; // 데이터 반환
	}
}

//추가 함수 1
int get_count(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}
//추가함수 2
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	
	for (p = q->front; p != NULL; p = p->link) {
		printf("%s ", p->data.name);
	}
}

int main(void) {
	LinkedQueueType men;
	LinkedQueueType women;
	element e;

	int quit = 0;
	char input;
	char name[20];
	char gender;
	int numM, numF, is_full_M = 0, is_full_F = 0;

	init(&men);
	init(&women);

	printf("미팅 주선 프로그램입니다.");
	while (quit != 1) {
		is_full_M = 0, is_full_F = 0;
		strcpy(e.name, "");

		printf("\ni<nsert,고객입력>,c<heck, 대기자 체크>, q<uit>:");
		scanf("%c", &input);


		switch (input)
		{
		case 'q':
			quit = 1;
			break;
		case 'i':
			printf("이름을 입력:");
			scanf("%s", &name);

			getchar();//버퍼비우기

			printf("성별을 입력<m of f>:");
			scanf("%c", &gender);

			if (gender == 'm') {
				strcpy(e.name, name);

				if (is_full(&men))
					is_full_M = 1;
				if (!is_full_M) {
					enqueue(&men, e);
					if (is_empty(&women))
						printf("아직 대상자가 없습니다. 기다려주십시오");
					else
						printf("커플이 탄생했습니다! %s와 %s", dequeue(&men).name, dequeue(&women).name); //dequeue의 return값인 element에 있는 name 반환
				}
				if (is_full_M && is_empty(&women))
					printf("아직 대상자가 없습니다.");
				if (is_full_M)
					printf("대기자가 꽉찼으니 담기회를 이용");

			}
			else if (gender == 'f') {
				strcpy(e.name, name);

				if (is_full(&women))
					is_full_F = 1;
				if (!is_full_F) {
					enqueue(&women, e);
					if (is_empty(&men))
						printf("아직 대상자가 없습니다. 기다려주십시오");
					else
						printf("커플이 탄생했습니다! %s와 %s", dequeue(&women).name, dequeue(&men).name); //dequeue의 return값인 element에 있는 name 반환
				}
				if (is_full_F && is_empty(&men))
					printf("아직 대상자가 없습니다.");
				if (is_full_F)
					printf("대기자가 꽉찼으니 담기회를 이용");

			}
			else
				printf("오타입니다");
			break;

		case 'c': //difficult!
			numM = get_count(&men);
			printf("남성 대기자 %d명:", numM);
			if (numM)
				print_queue(&men);

			numF = get_count(&women);
			printf("\n여성 대기자 %d명:", numF);
			if (numF)
				print_queue(&women);

			break;
		default:
			break;
		}
		getchar();//버퍼비우기
	}
}