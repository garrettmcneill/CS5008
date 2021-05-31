#include <stdio.h>
#include <string.h>


char input[140];    // declare input array with max chars


int main(void) {

    // do while scheme for quitting when user says to quit loosely based on
    // https://stackoverflow.com/questions/55033405/type-quit-to-quit-c-program/55033679
    do {
        char c;     /* final character read */
        int retn;   /* variable to save scanf return */
        /* prompt */
        fputs("Enter a bunch of words ('quit' exits): ", stdout);
        /* read saving scanf return */
        retn = scanf(" %199[^\n]%c", input, &c);
        if (retn == (strcmp(input, "quit")) {      /* check the return against EOF */
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

    return 0;
}