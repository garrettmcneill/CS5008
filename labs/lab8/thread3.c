// Compile with:
//
// clang -lpthread thread3.c -o thread3
// or
// gcc -lpthread thread3.c -o thread3
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 40000l //updated to long

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
    pthread_t tid[NTHREADS];
    long i, group;  // changed int i to long i

    printf("Counter starts at %ld \n", counter);

    // create and run the thread groups
    for (i = 0; i < NTHREADS; ++i) {
        // group # is the (index mod 4) + 1
        group = (i % 4) + 1;
        // printf("i: %ld, group: %ld \n", i, group);
        switch(group){
            case 1:
                pthread_create(&(tid[i]), NULL, thread1, NULL);
                break;
            case 2:
                pthread_create(&(tid[i]), NULL, thread2, NULL);
                break;
            case 3:
                pthread_create(&(tid[i]), NULL, thread3, NULL);
                break;
            case 4:
                pthread_create(&(tid[i]), NULL, thread4, NULL);
                break;
            default:
                break;
        }
    }
    printf("%ld threads created \n", NTHREADS);

    //wait until all threads are done
    for (i = 0; i < NTHREADS; ++i) {
        printf("joining i: %ld \n", i);
        pthread_join(tid[i], NULL);
    }
    printf("%ld threads joined \n", NTHREADS);

    // print final counter
    printf("Counter ends at %ld\n", counter);

    return 0;
}
