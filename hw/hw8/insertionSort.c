#include "insertionSort.h"


/**
 * Insertion sort, implementation from: https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_program_in_c.htm
 * @param array - the array to be sorted.
 * @param elements - the number of elements in an array.
 */
void insertionSort(int intArray[], int elements) {

    int valueToInsert;
    int holePosition;
    int i;
    int compareCount = 0;
    int moveCount = 0;

    //time keeper
    clock_t startTime, endTime;
    long timeDiff;
    double durationSecs;

    // loop through all numbers
    startTime = clock(); // start clock
    for(i = 1; i < elements; i++) {

        // select a value to be inserted.
        valueToInsert = intArray[i];

        // select the hole position where number is to be inserted
        holePosition = i;

        // check if previous no. is larger than value to be inserted
        while (holePosition > 0 && intArray[holePosition-1] > valueToInsert) {
            ++compareCount; // increment comparison counter
            intArray[holePosition] = intArray[holePosition-1];
            ++moveCount; // increment move counter
            holePosition--;
            printf(" item moved : %d\n" , intArray[holePosition]);
        }

        if(holePosition != i) {
            printf(" item inserted : %d, at position : %d\n" , valueToInsert,holePosition);
            // insert the number at hole position
            intArray[holePosition] = valueToInsert;
            ++moveCount; // increment move counter
        }

        printf("Iteration %d#:",i);

    }
    endTime = clock();  // end clock
    timeDiff = (endTime - startTime);
    durationSecs = ((double) timeDiff) / CLOCKS_PER_SEC;

    printf("\n\n start time: %ld, end time: %ld, diff: %ld \n", startTime, endTime, timeDiff);


    printf("\n\n- - - - Insertion Sort - - - -\n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}