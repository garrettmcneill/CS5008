#include "shellSort1.h"

/**
 * Shell sort, implementation loosely based on https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm
 *
 * @param intArray - the array to be sorted.
 * @param elements - the number of elements in the array.
 */
void shellSort1(int intArray[], int elements) {
    int inner, outer;
    int valueToInsert;
    int interval = 1;
    int i = 0;
    int compareCount = 0, moveCount = 0;
    double base, exp, result;
    int limit;

    //time keeper
    clock_t startTime, endTime;
    long timeDiff;
    double durationSecs;

    startTime = clock(); // start clock

    base = elements;
    exp = (1.0/3.0);
    result = 1.72 * pow(base, exp);
    limit = result;
    printf("limit: %d \n", limit);

    while ( interval < limit ){
        base = interval;
        result = 1.72 * pow(base, exp);
        interval = result + 0.5;
        printf("interval: %d \n", interval);
    }
    printf("end first while loop...starting second\n");

    while(interval > 0) {
        printf("iteration %d#:, interval %d \n", i, interval);

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
        //    printf(" item inserted :%d, at position :%d\n",valueToInsert,inner);
        }

        //interval = (interval -1) /3;
        base = (1.0 * interval) / 1.72;
        exp = 3.0;
        result = pow(base, exp);
        interval = result + 0.5;
        i++;
    }
    printf("end second while loop\n");

    endTime = clock();  // end clock
    timeDiff = (endTime - startTime);
    durationSecs = ((double) timeDiff) / CLOCKS_PER_SEC;

    printf("- - - - Shell Sort 1 - - - -\n");
    printf("Algo: { 1.72n^(1/3), 1 } \n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}
