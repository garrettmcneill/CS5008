#include <stdio.h>
#include <stdlib.h>

void updateArray1(int array[]){
    array[0] = 10;
}

int main(){
    int numbers[3] = {1,2,3};

    updateArray1(&numbers);

    printf("sizeof(int): %d\n", sizeof(int));
    printf("\n");

    printf("%p\n", &numbers[0]);
    printf("%p\n", &numbers[1]);
    printf("%p\n", &numbers[2]);

    return 0;
}