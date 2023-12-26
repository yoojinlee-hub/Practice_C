#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(int* a,int* b){
    return *a - *b;
}
// 중복된 값이 있는 int 배열을 받아 중복을 제거한 새로운 배열을 반환
int* removeDuplicates(int arr[], int size, int* newSize) {
    // 중복을 제거한 배열을 저장할 동적 할당 메모리
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        // 동적 할당 실패 시 예외 처리
        *newSize = 0;
        return NULL;
    }

    int count = 0; // 중복을 제거한 배열의 현재 크기

    for (int i = 0; i < size; i++) {
        int j;
        // 중복된 값이 있는지 확인
        for (j = 0; j < count; j++) {
            if (arr[i] == result[j]) {
                break;
            }
        }

        // 중복된 값이 없으면 결과 배열에 추가
        if (j == count) {
            result[count++] = arr[i];
        }
    }

    // 중복을 제거한 배열의 크기를 반환
    *newSize = count;
    return result;
}

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count = 0, sum = 0;
    int* answer = (int*)malloc(sizeof(int)*numbers_len*(numbers_len-1));
    int newSize;
    qsort(numbers,numbers_len,sizeof(int),compare);
    
    //서로 다른 인덱스에 있는 두 개의 수 뽑아서 더하기
    for(int i=0;i<numbers_len;i++){
        for(int j=0;j<numbers_len;j++){
            sum = 0;
            if(i != j){
                sum = numbers[i] + numbers[j];
                answer[count] = sum;
                count++;
            }
        }
    }
    
    qsort(answer,count,sizeof(int),compare);
    answer = removeDuplicates(answer,count,&newSize);
    //중복 제거
    
    return answer;
}