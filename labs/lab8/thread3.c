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
#define NGROUPS 4

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
    pthread_t tid[NROWS][NGROUPS];
    int row, group;

    printf("Counter starts at %ld \n", counter);

    // create and run the thread groups
    for (row = 0; row < NROWS; ++row) {
        for (group = 0; group < NGROUPS; ++group){

            // printf("i: %ld, group: %ld \n", row, group);
            switch(group){
                case 0:
                    pthread_create(&(tid[row][group]), NULL, thread1, NULL);
                    break;
                case 1:
                    pthread_create(&(tid[row][group]), NULL, thread2, NULL);
                    break;
                case 2:
                    pthread_create(&(tid[row][group]), NULL, thread3, NULL);
                    break;
                case 3:
                    pthread_create(&(tid[row][group]), NULL, thread4, NULL);
                    break;
                default:
                    break;
            }
        }

    }
    printf("%d rows of %d groups of threads created \n", NROWS, NGROUPS);

    //wait until all threads are done
    for (row = 0; row < NROWS; ++row) {
        for (group = 0; group <NGROUPS; ++group){
            printf("joining row: %d, group: %d \n", row, group);
            pthread_join(tid[row][group], NULL);
        }
    }
    printf("%d rows of %d groups of threads joined \n", NROWS, NGROUPS);

    // print final counter
    printf("Counter ends at %ld\n", counter);

    return 0;
}
