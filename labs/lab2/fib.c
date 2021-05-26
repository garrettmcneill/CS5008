#include <stdio.h>


long fib(long n){
    // unsigned long array to store fib numbers up
    long f[50];
    long i;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


int main(){

    long n = 9;
    printf("%20lu", fib(n));
    return 0;
}