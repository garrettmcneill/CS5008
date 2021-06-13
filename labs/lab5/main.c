#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab5.h"

char input[140];


int main() {


    // do while loop to continuously ask for input unless user types quit
    do {

        int retn;

        // get user input & read returning scan return
        fputs("input a string (QUIT for done): ", stdout);
        retn = scanf(" %199[^\n]", input);

        // check to see if user wants to quit
        if ( (strcmp(input, "QUIT") == 0 ) || (strcmp(input, "quit") == 0) ){
            printf("end program \n");
            return 0;

        } else {

            // check for palindrome

            // print string is/is not a palindrome

        }
    } while ((strcmp(input, "quit") != 0) && (strcmp(input, "QUIT") != 0));


    return EXIT_SUCCESS;
}
