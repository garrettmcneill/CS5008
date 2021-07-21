#include "shellSort.h"

/**
 * Shell sort, implementation from https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm
 *
 * @param intArray - the array to be sorted.
 * @param elements - the number of elements in the array.
 */
void shellSort(int intArray[], int elements) {
    int inner, outer;
    int valueToInsert;
    int interval = 1;
    int i = 0;
    int compareCount = 0, moveCount = 0;

    //time keeper
    struct timeval startTime, endTime;
    long durationMsecs;
    double durationSecs;

    gettimeofday(&startTime, NULL); // start clock

    while(interval < elements/3) {  //fixed this... <= should be <... didn't work for n=12
        interval = interval*3 +1;
    }

    while(interval > 0) {
        printf("iteration %d#:",i);

        for(outer = interval; outer < elements; outer++) {
            valueToInsert = intArray[outer];
            inner = outer;

            while(inner > interval -1 && intArray[inner - interval]
                                         >= valueToInsert) {
                ++compareCount; // increment comparison counter
                intArray[inner] = intArray[inner - interval];
                ++moveCount; // increment move counter
                inner -=interval;
                printf(" item moved :%d\n",intArray[inner]);
            }

            intArray[inner] = valueToInsert;
            ++moveCount; // increment move counter
            printf(" item inserted :%d, at position :%d\n",valueToInsert,inner);
        }

        interval = (interval -1) /3;
        i++;
    }
    gettimeofday(&endTime, NULL);  // end clock
    durationMsecs = (endTime.tv_usec - startTime.tv_usec) + (endTime.tv_sec - startTime.tv_sec) * 1000000;
    durationSecs = (1.0 * durationMsecs) / 1000000.0;

    printf("- - - - Insertion Sort - - - -\n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}