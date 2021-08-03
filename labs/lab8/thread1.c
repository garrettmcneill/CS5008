// Compile with:
//
// clang -lpthread thread1.c -o thread1
// or
// gcc -lpthread thread1.c -o thread1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// thread to be executed - unspecified variable arguments
void *thread (void *vargp) {
  printf("Hello from thread %ld\n", (long)pthread_self());
  return NULL;
}

int main() {
  // variable to keeo  Pthread ID of created thread
  pthread_t tid;

  printf("Hello from the main program\n");
  
  // create and run the thread
  pthread_create(&tid, NULL, thread, NULL);

  //wait until thread is done
  pthread_join(tid, NULL);

  printf("Good bye from the main program\n");

  return 0;
}
