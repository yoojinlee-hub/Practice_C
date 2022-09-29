#include <stdio.h>
void main(void)
{
	int n[] = { -1, 1, 2, 3, 4 };
	int* p1 = n;
	int* p2 = p1;
	printf("%d\n", n[0]);
	printf("%d\n", (*p1)++);
	printf("%d\n", n[0]);
	printf("%d\n", *p2++);
	// *(간접지정 연산)과 ++은 우선순위(p69)가 같다. 이때 결합방향이  이므로 오른 쪽에
	// 위치한 ++를 먼저 수행하고 그다음 *를 수행한다. 즉 *(p2++)와 같다.
	printf("%d\n", *p2);
	printf("%d\n", *++p1);
	printf("%d\n", *p1);
}