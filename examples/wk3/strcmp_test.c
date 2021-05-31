#include <stdio.h>
#include <string.h>


void empty_stdin(void) {
    int c = getchar();
    while (c != EOF && c != '\n')
        c = getchar();
}

char input[140];    /* use constants for array bounds */


int main(void) {


    do {


        // parse input for chars
        int i;
        for (i = 0; i < strlen(input); i++) {

            // parse & print lowercase chars
            if (('a' <= input[i]) && (input[i] <= 'z')) {
                printf("%c -- 0x%x\n", input[i] - 0x20, input[i] - 0x20);
            }
                // PARSE & PRINT UPPERCASE CHARS
            else if (('A' <= input[i]) && (input[i] <= 'Z')) {
                printf("%c -- 0x%x\n", input[i], input[i]);
            }
                // parse & print punctuation!?
            else if (('!' <= input[i]) && (input[i] <= '?')) {
                printf("%c -- 0x%x\n", input[i], input[i]);
            }
                // parse blank spaces
            else {
                printf("  -- 0x20\n");
            }

        }
        // print line break at end because prompt shows it
        printf("\\n  -- 0x20\n");


    } while ((strcmp(input, "quit") != 0) && (strcmp(input, "QUIT") != 0));

    return 0;
}