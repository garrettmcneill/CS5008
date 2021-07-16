#include <stdio.h>

void square(int *numPtr) {
	*numPtr = *numPtr * *numPtr;
}

int main() {
	int x = 4;
	square(&x);
	printf("%d\n", x);
	return 0;
}

