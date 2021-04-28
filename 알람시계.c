#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int H, M;
    scanf("%d %d", &H, &M);

    if ((H >= 0 && H <= 24) && M >= 45 && M <= 59)
        printf("%d %d\n", H, M - 45);
    else if ((H > 0 && H <= 24) && M >= 0 && M <= 44)
        printf("%d %d\n", H - 1, M + 15);
    else if (H == 0 && M <= 44)
        printf("23 %d\n", M + 15);
    else
        printf("정확한 시간을 입력해주세요.\n");

    return 0;
}