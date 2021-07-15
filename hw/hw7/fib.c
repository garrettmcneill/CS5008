#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Memo variables & initial values
long *fibArrayPtr = NULL;   // Pointer to the base of the fibonacci number array
long fibArrayMaxIdx = 0;    // Size of the fibonacci number array
long fibArrayIdx = 0;       // The index of the last fibonacci number calculated


/**
 * Legacy fibonacci function from lab 3
 * @param n
 * @return
 */
long fib(long n) {
    // unsigned long array to store fib numbers up to n
    long f[n];
    long i;

    // where fib(0) = 0, fib (1) = 1
    f[0] = 0;
    f[1] = 1;

    // loop through fib seq recursively
    for (i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}


/**
 * Fibonacci function utilizing memoization.
 * @param n
 * @return
 */
long mfib(long n) {
    int idx;

    // special cases
    if (n < 0) {
        printf("Parameter of mfib must be greater than 0.\n");
        return -1;
    } else if (n > fibArrayMaxIdx) {
        printf("Parameter of mfib cannot be larger than the maximum of %lu \n", fibArrayMaxIdx);
        return -1;
    } else if (n <= fibArrayIdx) {
        return fibArrayPtr[n];
    }

    // normal case extends the array
    for (idx = fibArrayIdx + 1; idx <= n; ++idx) {
        fibArrayPtr[idx] = fibArrayPtr[idx - 1] + fibArrayPtr[idx - 2];
    }
    fibArrayIdx = n;

    return fibArrayPtr[n];
}


/**
 * Function allocates space for as many numbers that we will ever calculate.
 * Initializes the first two values (0, 1)
 * @param maxN
 * @return
 */
void initMemo(long maxN) {
    if (fibArrayPtr != NULL) {
        free(fibArrayPtr);
        fibArrayPtr = NULL;
    }
    fibArrayMaxIdx = maxN;
    fibArrayPtr = malloc(sizeof(long) *fibArrayMaxIdx);
    fibArrayPtr[0] = 0l;
    fibArrayPtr[1] = 1l;
    fibArrayIdx = 1;
}


// ========================== MAIN PROGRAM  ==========================
int main() {

    //time keeper
    struct timeval startTime, endTime;
    long durationMsecs;

    printf("Non-Memoized Version of fib():\n");
    // declare total fib numbers to generate
    long itr;
    for (itr = 1; itr <= 50; itr+=5) {
        gettimeofday(&startTime, NULL); // start clock
        printf("fib(%lu) = %25lu \n", itr, fib(itr));
        gettimeofday(&endTime, NULL);  // end clock
        durationMsecs = (endTime.tv_usec - startTime.tv_usec) + (endTime.tv_sec - startTime.tv_sec) * 1000000;
        printf("\nTime for fib() = %ld mSecs", durationMsecs);
    }

    printf("\n- - - - - - - - - - - - - - - \n\n");

    printf("Memoized Version of fib():\n");
    initMemo(50);
    for (itr = 1; itr < 90; itr+=5) {
        gettimeofday(&startTime, NULL); // start clock
        printf("fib(%lu) = %25lu \n", itr, mfib(itr));
        gettimeofday(&endTime, NULL);  // end clock
        durationMsecs = (endTime.tv_usec - startTime.tv_usec) + (endTime.tv_sec - startTime.tv_sec) * 1000000;
        printf("\nTime for fib() = %ld mSecs\n", durationMsecs);
    }

    return 0;
}

