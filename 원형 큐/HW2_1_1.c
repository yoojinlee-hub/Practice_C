//20191770 컴퓨터학과 이유진
// HW2_1_1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_QUEUE_SIZE 3

typedef struct {
	char name[20];
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

// 초기화함수
void init(QueueType* q) {
	q->front = 0; q->rear = 0;
}

//공백상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
	return (q->front) % MAX_QUEUE_SIZE == (q->rear + 1) % MAX_QUEUE_SIZE;
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//엿보기 함수
element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

//추가 함수 1
int get_count(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return (q->rear % MAX_QUEUE_SIZE) - (q->front % MAX_QUEUE_SIZE);
}
//추가함수 2
void print_queue(QueueType* q) {
	int index = q->front;
	int rear = q->rear;
	char content[20] = "";

	while (1) {
		strcpy(content, q->queue[(index + 1) % MAX_QUEUE_SIZE].name);//peek sudo
		printf("%s ", content); 
		index = (index + 1) % MAX_QUEUE_SIZE; //dequeue sudo
		if (index == rear)  //is_empty sudo
			break;
	}
}

int main(void) {
	QueueType men;
	QueueType women;
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
				if(is_full_F)
					printf("대기자가 꽉찼으니 담기회를 이용");
				
			}
			else
				printf("오타입니다");
			break;

		case 'c': //difficult!
			numM = (men.rear % MAX_QUEUE_SIZE) - (men.front % MAX_QUEUE_SIZE);
			
			printf("남성 대기자 %d명:", numM);
			if (numM)
				print_queue(&men);


			numF = (women.rear % MAX_QUEUE_SIZE) - (women.front % MAX_QUEUE_SIZE);
			
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