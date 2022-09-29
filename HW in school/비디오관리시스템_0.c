/***********
비디오관리시스템0
************/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CHAR 100 // 문자열의 max 문자
#include <stdio.h>
#include <string.h>


struct VideoInfo { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR];
	int qty; // 수량
};


int main(void)
{
	int videoCount = 5;
	struct VideoInfo videoList[MAX_VIDEO] = { {"BeforeSunrise",1},{"BeforeSunset",3},{"BeforeMidnight",5},{"Casablanca",7},{"EdgeOfTomorrow",9}}; // 앞의 정보처럼 초기화
	char title[MAX_CHAR];
	int qty; //수량
	// 필요한 변수 추가
	int choice;
	int cnt;
	int i;

	printf("1(All Video 출력), 2(구입), 3(검색), 4(종료): ");
	scanf("%d", &choice);

	while (choice != 4) {
		switch (choice) {
		case 1: // 보유 Video들을 출력
			printf("Video 제목\t 수량\n");
			printf("-----------------------\n");
			// 구현
			for (i = 0; i < videoCount; i++)
				printf("%s  %d\n", videoList[i].title, videoList[i].qty);
			break;


		case 2: // Video 구입
			cnt = 0;
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);
			// 구현
			for (i = 0; i < videoCount; i++)
				if (strcmp(videoList[i].title,title) == 0) {//같은게 있을 때
					videoList[i].qty += qty;
					cnt++; //있음
				}
			if (!cnt) { //없음
				videoCount++;
				strcpy(videoList[i].title, title);//videoList[i + 1].title = title;
				videoList[i].qty += qty;
			}

			break;


		case 3: // title 로 Video 찾기
			cnt = 0;
			printf("Enter video 제목: ");
			scanf("%s", title);
			//구현
			for (i = 0; i < videoCount; i++) 
				if (strcmp(title, videoList[i].title) == 0) {//같은게 있을 때
					if (videoList[i].qty >= 1)
						printf("대여 가능합니다\n");
					else
						printf("대여 불가능합니다\n");
					cnt++; //있음
				}
			if (!cnt)
					printf("그런 비디오는 없습니다\n");
			break;
		}
		printf("1(All Video 출력), 2(구입), 3(검색), 4(종료): ");
		scanf("%d", &choice);
	}
}