#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    int index1=0, index2=0;
    int find = 0;
    
    for(int i=0;i<goal_len;i++){
        
        if(index1 < cards1_len && !strcmp(cards1[index1], goal[i])) {
            index1 +=1; 
            find += 1;
        }else if (index2 < cards2_len && !strcmp(cards2[index2], goal[i])){
            index2 +=1; 
            find += 1;
        }else
            break;
    }   
    
    
    if (find == goal_len) {
        // Dynamically allocate memory for the result
        char* result = (char*)malloc(sizeof(char) * 4);
        strcpy(result, "Yes");
        return result;
    } else {
        // Dynamically allocate memory for the result
        char* result = (char*)malloc(sizeof(char) * 3);
        strcpy(result, "No");
        return result;
    }
    
}