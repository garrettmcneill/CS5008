#include <stdio.h>
#include <string.h>


int main() {

    char input[140];
    int i;
    int j;
    int k;

    // do while loop to continuously prompt user for input unless "quit"
    do {
        printf("\ninput a string (QUIT for done): ");
        gets(input);


        // string match check for "quit" , "QUIT" , or "QUIT\n"

        for ( (int k = 0; (k < strlen(s1)) ) && (k < strlen(s2)); k++ ){

            if (s1[k] == s2[k]) {
                // do nothin'
            } else if (s1[k] < s2[k]) {
                // return s1 is less than s2
            } else if (s1[k] > s2[k]) {
                // return s1 is greater than s2
            }
        }

        // we ran out of letters in one string, so far all the same...

        if (strlen(s1) < strlen(s2)) {
            // return that s1 is less than s2

        } else if (strlen(s1) > strlen(s2)) {
            // return that s1 is greatern than s2
        } else {
            // return that s1 equals s2
        }


        // parse input for chars
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


    } while (j > 0);


    return 0;
}