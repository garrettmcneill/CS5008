#include <stdio.h>


long fib(long n){
    // unsigned long array to store fib numbers up to n
    long f[n];
    long i;

    // where fib(0) = 0, fib (1) = 1
    f[0] = 0;
    f[1] = 1;

    // loop through fib seq recursively
    for (i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


int main(){

    // declare starting value of the fib sequence
    long n = 9;
    // iterator
    long itr;

    for(itr = 0; itr < n; itr++)
        printf("%20lu ", fib(itr));
    printf("\n");
    return 0;
}

