// Compile with:
//
// clang -lpthread thread2.c -o thread2
// or
// gcc -lpthread thread2.c -o thread2
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

// thread to be executed - unspecified variable arguments
void *thread (void *vargp) {
  printf("Hello from thread %ld\n", (long)pthread_self());
  return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS];
  int i;

  printf("Hello from the main program: %ld\n", (long)pthread_self());
  
  // create and run the thread
  for (i=0; i < NTHREADS; ++i){
    pthread_create(&(tid[i]), NULL, thread, NULL);
  }

  //wait until all threads are done
  for (i=0; i < NTHREADS; ++i){
    pthread_join(tid[i], NULL);
  }

  printf("Good bye from the main program: %ld\n", (long)pthread_self());

  return 0;
}
