/*
숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서, 이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를 return하는 함수 solution을 완성하세요.

예를 들어, t="3141592"이고 p="271" 인 경우, t의 길이가 3인 부분 문자열은 314, 141, 415, 159, 592입니다. 이 문자열이 나타내는 수 중 271보다 작거나 같은 수는 141, 159 2개 입니다.
https://school.programmers.co.kr/learn/courses/30/lessons/147355#qna
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    long answer = 0, p_num = atol(p);
    long t_size = strlen(t), p_size = strlen(p);

    // t_cp에 메모리 할당 후 문자열 복사
    char *t_cp = (char*)malloc((t_size + 1) * sizeof(char));
    

    // num_char에 메모리 할당
    char *num_char = (char*)malloc((p_size + 1) * sizeof(char));
strcpy(t_cp, t);
    // 나올 수 있는 최대 가짓수 = t_size - p_size + 1
    for (long i = p_size; i <= t_size; i++) {
        if (i > t_size) {
            break;  // i가 t_size를 초과하면 종료
        }

        strncpy(num_char, t_cp + i - p_size, p_size);
        num_char[p_size] = '\0'; // 수동으로 널 종료 문자 추가

        // atoi 변환 성공 여부 확인
        long num = atol(num_char);
        if (num != 0 || (num == 0 && num_char[0] == '0')) {
            if (num <= p_num) 
                answer += 1;
        }
    }

    // 동적으로 할당한 메모리 해제
    free(num_char);
    free(t_cp);

    return answer;
}
