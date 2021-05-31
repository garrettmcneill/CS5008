#include <stdio.h>
#include <string.h>


char input[140];    // declare input array with max chars


int main(void) {

    do {
        char c;
        int retn;   /* variable to save scanf return */

        fputs("input a string (QUIT for done): ", stdout);
        /* read saving scanf return */
        retn = scanf(" %199[^\n]%c", input, &c);

        if ( (strcmp(input, "QUIT") == 0 ) || (strcmp(input, "quit") == 0) ){
            printf("end program \n");
            return 0;
        } else {

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

        }
    } while ((strcmp(input, "quit") != 0) && (strcmp(input, "QUIT") != 0));

        printf("end program 2\n");



    return 0;
}