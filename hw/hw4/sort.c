#include <stdio.h>
#include <stdlib.h>

void sort(int *arrayPtr, int arraySize) {
    if (arrayPtr == NULL || arraySize <= 0) {
        printf("Something is wrong, array does not exist or is size 0.");
    }

    // declare vars
    int leastIdx;
    int leastValue, tmpValue;
    int baseIdx, tmpIdx;


    for (baseIdx = 0; baseIdx < arraySize - 1; ++baseIdx) {
        // find index of least value in the range of baseIdx+1 to arraySize-1
        leastIdx = baseIdx;
        leastValue = arrayPtr[leastIdx];
        for (tmpIdx = baseIdx + 1; tmpIdx < arraySize; ++tmpIdx) {
            if (arrayPtr[tmpIdx] < leastValue) {
                leastIdx = tmpIdx;
                leastValue = arrayPtr[leastIdx];
            }
        }

        // if least index item value less than baseIdx value, then swap
        if (leastIdx > baseIdx){
            tmpValue = arrayPtr[leastIdx];
            arrayPtr[leastIdx] = arrayPtr[baseIdx];
            arrayPtr[baseIdx] = tmpValue;
        }
    }

    return;
}


int main() {

    int randInts[100];

    time_t t;
    int idx;

    // Intialize random number generator
    srand((unsigned) time(&t));

    for(idx = 0; idx <100; ++idx){
        randInts[idx] = rand() % 100;
    }

    // print unsorted array
    printf("Source Array: \n");
    for(idx = 0; idx <100; ++idx){
        printf("%02d ", randInts[idx]);
        if (idx %20 == 19){
            printf("\n");
        }
    }

    // sort array
    sort(randInts, 100);

    // print sorted array
    printf("\n\nDestination Array: \n");
    for(idx = 0; idx <100; ++idx){
        printf("%02d ", randInts[idx]);
        if (idx %20 == 19){
            printf("\n");
        }
    }

    return 0;
}

