#include <stdio.h>
#include <string.h>

int main() {
    // Stack memory
	char str[15];

    strncpy(str, "hakuna matata!", 15);

	printf("%s\n", str);

    // Heap memory
    char * strPtr;

    strPtr = (char *) malloc(15);

    strncpy(strPtr, "hakuna matata!", 15);

    printf("%s\n", strPtr);

    free(strPtr);
    strPtr = NULL;
 	                         			
	return 0;
}

