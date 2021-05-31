#include <stdio.h>
#include <string.h>

#define MAXC 200    /* constant - maximum characters in string */

void empty_stdin(void) {
    int c = getchar();
    while (c != EOF && c != '\n')
        c = getchar();
}

int main(void) {

    char input[MAXC];    /* use constants for array bounds */

    do {
        char c;     /* final character read */
        int retn;   /* variable to save scanf return */
        /* prompt */
        fputs("Enter a bunch of words ('quit' exits): ", stdout);
        /* read saving scanf return */
        retn = scanf(" %199[^\n]%c", input, &c);
        if (retn == EOF) {      /* check the return against EOF */
            fputs("(user canceled input)\n", stderr);
            return 0;
        } else if (retn < 2) {    /* checking both string and c read */
            fputs("input failure.\n", stderr);
            empty_stdin();
        } else if (c != '\n') {   /* check c is '\n', else string too long */
            fprintf(stderr, "warning: input exceeds %d characters.\n",
                    MAXC - 1);
            empty_stdin();
        } else {  /* good input, output string */

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
    } while (strcmp(input, "quit") != 0);

    return 0;
}