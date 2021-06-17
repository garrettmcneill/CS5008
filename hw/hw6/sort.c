#include <stdio.h>
#include <stdlib.h>

// forward declaration of qsort
int comparator(const void *p, const void *q);


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
    //sort(randInts, 100);
    qsort((void*)randInts, 100, sizeof(int), comparator);


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

// comparator
int comparator(const void *p, const void *q)
{
    int l = *((int  *)p);
    int r = *((int  *)q);
    return (l - r);
}
