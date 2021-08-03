// Compile with:
//
// clang -lpthread thread4.c -o thread4
// or
// gcc -lpthread thread4.c -o thread4
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10000

// shared variable
int counter = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;  //lock variable

// thread to be executed - unspecified variable arguments
void *thread (void *vargp) {
  pthread_mutex_lock(&mutex1);     // lock the mutex
       counter = counter + 1;
  pthread_mutex_unlock(&mutex1);  // unlock the mutex
  return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS];
  int i;

  printf("Counter starts at %d\n", counter);
  
  // create and run the thread
  for (i=0; i < NTHREADS; ++i){
    pthread_create(&(tid[i]), NULL, thread, NULL);
  }

  //wait until all threads are done
  for (i=0; i < NTHREADS; ++i){
    pthread_join(tid[i], NULL);
  }

  printf("Counter ends at %d\n", counter);

  return 0;
}
