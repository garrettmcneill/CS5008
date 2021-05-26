#include <stdio.h>


long fib(long n){
    // unsigned long array to store fib numbers up
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

    long n = 50;
    printf("%20lu", fib(n));
    printf("\n");
    return 0;
}