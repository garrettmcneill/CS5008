#include <stdio.h>
#include <stdlib.h>

// Lesson 9.1 Dynamically Resized Arrays as a Data Structure - Constructor and Destructor

typedef struct vector{
    int* data;
    int size;
    int capacity;
}vector_t;

vector_t* makeVector(int initCapacity){
    vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
    if ( vector == NULL ){
        return NULL;
    }

    // allocate memory for our data array
    vector->data = (int*)malloc(sizeof(int) *initCapacity);
    vector->size = 0;
    vector->capacity =initCapacity;

    return vector;
}

void freeVector(vector_t* vector){
    if ( vector == NULL ){
        return 0;
    }
    // first: delete data array, then delete vector from heap
    if ( vector->data != NULL ){
        free(vector->data);
    }
    free(vector);

}


int main(){
    return 0;
}