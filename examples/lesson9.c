#include <stdio.h>
#include <stdlib.h>

// Lesson 9.1 Dynamically Resized Arrays as a Data Structure - Constructor and Destructor

/**
 * Struct for vector data type.
 */
typedef struct vector{
    int* data;
    int size;
    int capacity;
}vector_t;

/**
 *  Helper function to make a vector.
 * @param initCapacity
 * @return
 */
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

/**
 *  freeVector from memory helper function.
 * @param vector - the address of a vector in memory to free
 */
void freeVector(vector_t* vector){
    if ( vector == NULL ){
        return;
    }
    // first: delete data array, then delete vector from heap
    if ( vector->data != NULL ){
        free(vector->data);
    }
    free(vector);
}



int main(){
    // constructed a vector on the heap with the help of make vector
    vector_t* aVector = makeVector(2);
    // delete vector from heap
    freeVector(aVector);
    // exit
    return 0;
}