#include <stdio.h>
#include <string.h>

// declare input array with max chars
char input[140];


int main(void) {

    // do while loop to continuously ask for input unless user types quit
    do {
        // var declarations
        //char c;
        int retn;

        // get user input & validate
        fputs("input a string (QUIT for done): ", stdout);
        retn = scanf(" %199[^\n]%c", input, &c);

        // check to see if user wants to quit
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

    return 0;
}