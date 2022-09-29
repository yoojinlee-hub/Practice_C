
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 200 // max customer
#define MAX_CHAR 100 // 문자열의 max 문자
#include <stdio.h>
#include <string.h>

typedef struct { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR];
	int qty; // 수량
}VideoInfo;

typedef struct { // 대출 대장: 대출해간 (고객 id와 video id)들을 저장
	int custId; // 고객 id : 1, 2, 3
	char title[MAX_CHAR]; // Video 제목
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount) {
	//구현 : 재고대장(videoList)에 있는 video정보 출력
	int i;
	printf("Video 제목\t 수량\n");
	printf("-----------------------\n");
	for (i = 0; i < videoCount; i++)
		printf("%s  %d\n", videoList[i].title, videoList[i].qty);
}
void purchaseVideo(VideoInfo videoList[], int* videoCountPtr, char* title, int qty) { //title은 배열이기 때문에 포인터
	//구현 : 제목, 수량을 입력받아서 재고대장에 저장
	//videoCount 한 개 증가
	//videoCount를 가르키는 '포인터'가 매개변수
	int i, cnt = 0;

	for (i = 0; i < *videoCountPtr; i++)
		if (strcmp(videoList[i].title, title) == 0) {//같은게 있을 때
			videoList[i].qty += qty;
			cnt++; //있음
		}
	if (!cnt) { //없음
		(*videoCountPtr)++;
		strcpy(videoList[i].title, title);//videoList[i + 1].title = title;
		videoList[i].qty = qty;
	}
}
int searchVideoByTitle(VideoInfo* videoList, int videoCount, char* title) {
	//구현: 있으면 인덱스 반환, 없으면 -1반환
	int i, cnt = 0;

	//구현
	for (i = 0; i < videoCount; i++) {
		if (strcmp(title, videoList[i].title) == 0) { //같은게 있을 때
			if (videoList[i].qty >= 1)
				return i;
			cnt++;
		}
	}
	if (!cnt)
		return -1;
	else
		return 0;
}
void rentVideo(VideoInfo videoList[], int videoCount, RentInfo rentList[], int* rentCount, char* title, int custId) {
	//구현: 항상 대여 가능한 Video에 대한 대여가 시도됨
	//SearchVideoByTitle 함수를 사용하여 해당 video의 인덱스를 찾는다
	static int count = 0;
	int isit = searchVideoByTitle(videoList, videoCount, title);
	if (isit == -1)
		printf("대여 불가능합니다.\n");
	else {
		//rentCount를 한 개 증가, 해당 video 수량 한 개 감소
		(*rentCount)++;
		videoList[isit].qty -= 1;
		//고객 id와 video 제목을 대출대장(rentList)에 저장
		rentList[count].custId = custId;
		strcpy(rentList[count].title, title);
		count++;
	}
}
void printAllRent(RentInfo* rentList, int rentCount) {
	//구현
	int i;
	printf("고객id\t Video 제목\n");
	printf("-----------------------\n");
	for (i = 0; i < rentCount; i++) {
		printf("%d  %s\n", rentList->custId, rentList->title);
		rentList++;
	}
}
void readVideo(VideoInfo videoList[], int* videoCountPtr) {
	FILE* fp;
	VideoInfo video;

	if ((fp = fopen("video.txt", "r")) == NULL) {
		printf("입력 파일 오픈 실패\n");exit(1);
	}
	//비디오 정보를 입력파일에서 읽기
	while (fscanf(fp, "%s %d", video.title, &video.qty) != EOF) {
		videoList[*videoCountPtr] = video;
		(*videoCountPtr)++;
	}

	fclose(fp);
	
}
void writeVideo(VideoInfo videoList[], int videoCount) {
	FILE* fp, * fp1;
	int i;
	char buf[MAX_VIDEO];

	if ((fp = fopen("video.txt", "w")) == NULL) {
		printf("출력 파일 오픈 실패\n");
		exit(1);
	}
	
	//비디오 정보를 출력파일로 쓰기
	for (i = 0; i < videoCount; i++) 
		fprintf(fp, "%s %d\n", videoList[i].title, videoList[i].qty);
		
	fclose(fp);
	
}
void writeRent(RentInfo rentList[], int rentCount) {
	FILE* fp;
	int i;

	fp = fopen("rent.txt", "w");
	if (fp == NULL) {
		printf("출력 파일 오픈 실패\n");
		exit(1);
	}
	for (i = 0; i < rentCount; i++)
		fprintf(fp, "%d %s\n", rentList[i].custId, rentList[i].title);
	fclose(fp);
}
int main(void)
{
	int videoCount = 0;//초기화
	VideoInfo videoList[MAX_VIDEO];
	int rentCount = 0; // 현재 대출 건수는 0임
	RentInfo rentList[MAX_CUST];

	int choice;
	int indexSearched;
	char title[MAX_CHAR];
	int custId, qty;

	readVideo(videoList, &videoCount);

	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);

	while (choice != 6) {
		switch (choice) {
		case 1:
			printAllVideo(videoList, videoCount);
			break;
		case 2:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);
			purchaseVideo(videoList, &videoCount, title, qty);
			break;
		case 3:
			printf("Enter video 제목: ");
			scanf("%s", title);
			if ((indexSearched = searchVideoByTitle(videoList, videoCount, title)) == -1)
				printf("그런 비디오는 없습니다.\n");
			else if (videoList[indexSearched].qty == 0)
				printf("다 대여중입니다.\n");
			else
				printf("대여 가능합니다.\n");
			break;
		case 4:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter 고객 id: ");
			scanf("%d", &custId);
			rentVideo(videoList, videoCount, rentList, &rentCount, title, custId);
			break;
		case 5:
			printAllRent(rentList, rentCount);
			break;
		}
		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
		scanf("%d", &choice);

	}
	writeVideo(videoList, videoCount);
	writeRent(rentList, rentCount);
}