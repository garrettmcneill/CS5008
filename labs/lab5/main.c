#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab5.h"


int main() {

    char input[140];
    int retn;
    bool bTemp;

    // do while loop to continuously ask for input unless user types quit
    do {

        // get user input & read returning scan return
        fputs("input a string (QUIT for done): ", stdout);
        retn = scanf(" %199[^\n]", input);

        // check to see if user wants to quit
        if ( (strcmp(input, "QUIT") == 0 ) || (strcmp(input, "quit") == 0) ){
            printf("end program \n");
            return 0;

        } else {
            // check for palindrome
            bTemp = is_palindrome(input);

            // print string is/is not a palindrome
            printf("%s ", input);
            if (bTemp){
                printf("is a palindrome. \n");
            } else{
                printf("is not a palindrome. \n");
            }

        }
    } while ((strcmp(input, "quit") != 0) && (strcmp(input, "QUIT") != 0));


    return EXIT_SUCCESS;
}
