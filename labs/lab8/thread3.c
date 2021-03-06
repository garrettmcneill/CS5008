// Compile with:
//
// clang -lpthread thread3.c -o thread3
// or
// gcc -lpthread thread3.c -o thread3
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NROWS 10000

// shared variable
long counter = 0;

// thread function for group 1
void *thread1(void *vargp) {
    counter = counter + 1;
    return NULL;
}

// thread function for group 2
void *thread2(void *vargp) {
    counter = counter + 5;
    return NULL;
}

// thread function for group 3
void *thread3(void *vargp) {
    counter = counter - 2;
    return NULL;
}

// thread function for group 4
void *thread4(void *vargp) {
    counter = counter - 10;
    return NULL;
}


int main() {
    // array to keep Pthread IDs of created threads
    // the size of an array is a size_t (max size is an unsigned_int on most
    // platforms.) therefore we cannot have an array bigger than 32,768...
    // so we must use a 2-dimensional array.
    pthread_t tid1[NROWS];
    pthread_t tid2[NROWS];
    pthread_t tid3[NROWS];
    pthread_t tid4[NROWS];

    int row, createErr;
    int maxRowsCreated = 0;

    printf("Counter starts at %ld \n", counter);

    // create and run the thread groups
    for (row = 0; row < NROWS; ++row) {
        // printf("i: %ld, group: %ld \n", row, group);
        createErr = pthread_create(&(tid1[row]), NULL, thread1, NULL);
        if (createErr != 0) break; // end loop if error
        createErr = pthread_create(&(tid2[row]), NULL, thread2, NULL);
        if (createErr != 0) break;
        createErr = pthread_create(&(tid3[row]), NULL, thread3, NULL);
        if (createErr != 0) break;
        createErr = pthread_create(&(tid4[row]), NULL, thread4, NULL);
        if (createErr != 0) break;

        ++maxRowsCreated;
    }

    printf("%d rows created in each thread group \n", maxRowsCreated);

    //wait until all threads are done
    for (row = 0; row < maxRowsCreated; ++row) {
      //  printf("joining row: %d \n", row);
        pthread_join(tid1[row], NULL);
        pthread_join(tid2[row], NULL);
        pthread_join(tid3[row], NULL);
        pthread_join(tid4[row], NULL);
    }

    printf("%d rows joined in each thread group\n", maxRowsCreated);

    // print final counter
    printf("Counter ends at %ld\n", counter);

    return 0;
}


/* Note: my process cannot create more than 32,752 threads.
 */