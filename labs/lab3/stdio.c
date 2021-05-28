#include <stdio.h>
#include <string.h>


int main() {

    char input[140];
    int i;

    printf("\ninput a string (QUIT for done): ");
    gets(input);


    for (i=0; i< strlen(input); i++) {
        printf("%c %.3d %x", input[i], input[i], input[i]);

        if ( ('a' <= input[i]) && ( input[i] <= 'z') ) {
            printf("-- upper case! %c\n", input[i]-0x20);
        } else {
            printf("\n");
        }
    }
    return 0;
}