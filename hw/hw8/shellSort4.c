#include "shellSort4.h"

/**
 * Shell sort, implementation loosely based on https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm
 *
 * @param intArray - the array to be sorted.
 * @param elements - the number of elements in the array.
 */
void shellSort4(int intArray[], int elements) {
    int inner, outer;
    int valueToInsert;
    int interval = 1;
    int i = 0;
    int compareCount = 0, moveCount = 0;
    int t = 0;
    double base;
    double exp;
    double result;

    //time keeper
    clock_t startTime, endTime;
    long timeDiff;
    double durationSecs;

    startTime = clock(); // start clock

    // loop to find value of t
    result = 4; // (3^2 -1 = 4)
    while (result < elements){
        base = 3;
        exp = t+2;
        result = ( pow(base, exp) - 1 ) / 2;
        ++t;
    //    printf("t: %d, result: %f \n", t, result);
    }

    // count down to 1
    i = t;
    while(i > 0) {

        // calculate interval (3^i - 1) / 2
        base = 3;
        exp = i;
        result = ( pow(base, exp) - 1 ) / 2;
        interval = result;
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
                //        printf(" item moved :%d\n",intArray[inner]);
            }

            intArray[inner] = valueToInsert;
            ++moveCount; // increment move counter
            //    printf(" item inserted :%d, at position :%d\n",valueToInsert,inner);
        }

        --i;
    }

    endTime = clock();  // end clock
    timeDiff = (endTime - startTime);
    durationSecs = ((double) timeDiff) / CLOCKS_PER_SEC;

    printf("- - - - Shell Sort 4 - - - -\n");
    printf("Algo: { (3^1 - 1) / 2  | 1 <= i <= t where t is the smallest integer \n      "
           "   such that (3^(t-2) -1) / 2 >= n } \n");
    printf("Sorting an array of size: %ld\n", elements);
    printf("%ld comparisons, %ld moves \n", compareCount, moveCount);
    printf("time taken (sec) = %10.6f \n\n", durationSecs);

}
