#include "sortCompare.h"

int main(int argc, char *argv[]) {

    // Constants
    int MAXVAL = 1024000;

    // Local vars
    int idx;

    if (argc < 2) {
        printf("Not enough arguments passed at creation of program ");
        return -1;
    }

    // convert argument string to int
    int numElements = atoi( argv[1] );

    // allocate array of size n from argument
    int *sortArray = calloc(sizeof(int), numElements);


    // - - - - INSERTION SORT - - - - //
    // Intialize random number generator
    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    insertionSort(sortArray, numElements);


    // - - - - SHELL SORT - - - - //
    // Intialize random number generator
/*    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    shellSort(sortArray, numElements);
*/

    // - - - - SHELL SORT 1 - - - - //
    // Intialize random number generator
    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    shellSort1(sortArray, numElements);


    // - - - - SHELL SORT 2 - - - - //
    // Intialize random number generator
    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    shellSort2(sortArray, numElements);


    // - - - - SHELL SORT 3 - - - - //
    // Intialize random number generator
    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    shellSort3(sortArray, numElements);


    // - - - - SHELL SORT 4 - - - - //
    // Intialize random number generator
    srand(12345);

    for(idx = 0; idx < numElements; ++idx){
        sortArray[idx] = rand() % MAXVAL;
    }

    shellSort4(sortArray, numElements);


    // free from memory
    free(sortArray);
    sortArray = NULL;

}