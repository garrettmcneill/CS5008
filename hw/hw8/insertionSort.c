#include "insertionSort.h"



/**
 * Insertion sort, implementation from: https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_program_in_c.htm
 * @param array - the array to be sorted.
 * @param elements - the number of elements in an array.
 */
void insertionSort(int array[], int elements) {

    int valueToInsert;
    int holePosition;
    int i;
    int compareCount = 0, moveCount = 0;

    //time keeper
    struct timeval startTime, endTime;
    long durationMsecs;
    double durationSecs;

    // loop through all numbers
    gettimeofday(&startTime, NULL); // start clock
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
        display();

    }
    gettimeofday(&endTime, NULL);  // end clock
    durationMsecs = (endTime.tv_usec - startTime.tv_usec) + (endTime.tv_sec - startTime.tv_sec) * 1000000;
    durationSecs = (1.0 * durationMsecs) / 1000000.0;

    printf("- - - - Insertion Sort - - - -\n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}