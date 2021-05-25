#include <stdio.h>
#include <stdlib.h>

// Lesson 9.1 Dynamically Resized Arrays as a Data Structure - Constructor and Destructor

typedef struct vector{
    int* data;
    int size;
    int capacity;
}vector_t;

vector_t* makeVector(int initCapacity){
    vector_t* vector = (vector_t*)malloc(sizeof(vector_t);
    if ( vector == NULL ){
        return NULL;
    }
}

int main(){
    return 0;
}