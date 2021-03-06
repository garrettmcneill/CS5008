#include "shellSort2.h"

/**
 * Shell sort, implementation loosely based on https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm
 *
 * @param intArray - the array to be sorted.
 * @param elements - the number of elements in the array.
 */
void shellSort2(int intArray[], int elements) {
    int inner, outer;
    int valueToInsert;
    int interval = 1;
    int i = 0;
    int compareCount = 0, moveCount = 0;
    double base;
    double exp;
    double result;

    //time keeper
    clock_t startTime, endTime;
    long timeDiff;
    double durationSecs;

    startTime = clock(); // start clock

    base = elements;
    result = log(base);
    i = result + 0.5;
    base = 2.0;
    exp = i;
    result = pow(base, exp) -1.0;
    interval = result + 0.5;


    while(i >= 1) {
        printf("i %d#:, interval %d \n", i, interval);

        for(outer = interval; outer < elements; outer++) {
            valueToInsert = intArray[outer];
            inner = outer;

            while(inner > interval -1 && intArray[inner - interval]
                                         >= valueToInsert) {
                ++compareCount; // increment comparison counter
                intArray[inner] = intArray[inner - interval];
                ++moveCount; // increment move counter
                inner -=interval;
    //            printf(" item moved :%d\n",intArray[inner]);
            }

            intArray[inner] = valueToInsert;
            ++moveCount; // increment move counter
    //        printf(" item inserted :%d, at position :%d\n",valueToInsert,inner);
        }

        --i;
        base = 2;
        exp = i;
        result = pow(base, exp) - 1.0;
        interval = result + 0.5;
    }

    endTime = clock();  // end clock
    timeDiff = (endTime - startTime);
    durationSecs = ((double) timeDiff) / CLOCKS_PER_SEC;

    printf("- - - - Shell Sort 2 - - - -\n");
    printf("Algo: { 2^i - 1 | 1 <= i <= [log n] } \n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}
