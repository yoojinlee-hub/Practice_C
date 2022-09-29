#include <stdio.h>

int main(void) {

	printf("%c\n", 'B' & 'a' | 'd');
	printf("%c\n", '~B' & 'a' | 'c');
}