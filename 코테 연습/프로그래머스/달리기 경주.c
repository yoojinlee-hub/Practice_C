/*
https://school.programmers.co.kr/learn/courses/30/lessons/178871
얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다. 예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때, 해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다. 즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와 해설진이 부른 이름을 담은 문자열 배열 callings가 매개변수로 주어질 때, 경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>  

// 구조체 정의
struct Person {
    char* name;
    int index;
};
// 비교 함수
int compareIndex(const void* a, const void* b) {
    return ((struct Person*)a)->index - ((struct Person*)b)->index;
}
// 구조체 배열 초기화 함수
struct Person* initializePeople(const char* names[], size_t length) {
    struct Person* people = (struct Person*)malloc(length * sizeof(struct Person));
    
    if (people == NULL) 
        exit(1);  // 실패 시 프로그램 종료
    
    // 각 구조체 초기화
    for (size_t i = 0; i < length; i++) {
        people[i].name = (char*)malloc((strlen(names[i]) + 1) * sizeof(char));
        
        if (people[i].name == NULL) {
            // 실패 시 이미 할당된 메모리 해제
            for (size_t j = 0; j < i; j++) {
                free(people[j].name);
            }
            free(people);
            exit(1);
        }
        
        strcpy(people[i].name, names[i]);
        people[i].index = i+1;
    }

    return people;
}

// 구조체 해제 함수
void freePeople(struct Person* people, size_t length) {
    for (size_t i = 0; i < length; i++) {
        free(people[i].name);
    }
    free(people);
}

char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
   // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(players_len * sizeof(char*));       
    
    // 구조체 배열 동적 초기화
    struct Person* people = initializePeople(players, players_len);
    
    
    for(int i = 0; i<callings_len ;i++){
        for(int j = 0; j < players_len ; j++){
            if(!strcmp(callings[i],people[j].name)){
                people[j].index -= 1;
                people[j-1].index += 1;
                //index 순서대로 정렬 필요
                qsort(people, players_len, sizeof(struct Person), compareIndex);
            }  
        }
    }
    
    for (size_t i = 0; i < players_len; i++) {
        answer[i] = (char*)malloc((strlen(players[i]) + 1) * sizeof(char));
        strcpy(answer[i], people[i].name);
    }
    
    // 해제
    freePeople(people, players_len);
    return answer;
}  