#include "dynarray.h"

/**************************************
 * BASE DYNAMIC ARRAY IMPLEMENTATION
 *************************************/

const int DEFAULT_DYNARRAY_CAPACITY = 2;

void dynarray_init(dynarray_t *a) {

    /* allocate space for data */
    a->array = (data_t*)malloc(DEFAULT_DYNARRAY_CAPACITY * sizeof(data_t));
    if (a->array == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for dynamic array.");
        exit(-1);
    }

    /* initialize other metadata */
    a->capacity = DEFAULT_DYNARRAY_CAPACITY;
    a->size = 0;
    a->front = 0;
}

void dynarray_expand(dynarray_t *a, size_t new_capacity) {

    size_t i;

    printf("dynarray_expand: old=%d, new=%d \n", a->capacity, new_capacity);

    /* allocate new array */
    data_t *new_array = (data_t*)malloc(new_capacity * sizeof(data_t));
    if (!new_array) {
        fprintf(stderr, "ERROR: Cannot allocate memory for dynamic array.");
        exit(-1);
    }

    /* copy items to new array */
    for (i = 0; i < a->size; i++) {
        new_array[i] = a->array[(a->front + i) % a->capacity];
    }

    /* delete old array and clean up */
    free(a->array);
    a->array = new_array;
    a->capacity = new_capacity;
    a->front = 0;
}

size_t dynarray_size(dynarray_t *a) {

    return a->size;
}

size_t dynarray_is_empty(dynarray_t *a) {

    return (a->size == 0);
}

void dynarray_free(dynarray_t *a) {

    free(a->array);
    a->array    = NULL;
    a->capacity = 0;
    a->size     = 0;
}


/**************************************
 *           STACK INTERFACE
 *************************************/

void dynarray_push(dynarray_t *a, data_t item) {

    printf("dynarray_push: size=%d, capacity=%d, item=%d\n", a->size, a->capacity, item);

    if (a->size+1 > a->capacity) {
        dynarray_expand(a, a->capacity*2);          /* expand if necessary */
    }
    a->array[a->size++] = item;
}

data_t dynarray_pop(dynarray_t *a) {

    assert(a->size > 0);
    return a->array[--(a->size)];
}

data_t dynarray_top(dynarray_t *a) {

    assert(a->size > 0);
    return a->array[a->size-1];
}


/**************************************
 *           QUEUE INTERFACE
 *************************************/

void dynarray_enqueue(dynarray_t *a, data_t item) {

    printf("dynarray_enque: front=%d, size=%d, item=%d\n", a->front, a->size, item);


    if (a->size+1 > a->capacity) {
        dynarray_expand(a, a->capacity*2);          /* expand if necessary */
    }
    a->array[(a->front + a->size) % a->capacity] = item;
    a->size++;
}

data_t dynarray_dequeue(dynarray_t *a) {

    assert(a->size > 0);
    data_t value = a->array[a->front];
    a->front = (a->front+1) % a->capacity;
    a->size--;
    return value;
}

data_t dynarray_front(dynarray_t *a) {

    assert(a->size > 0);
    return a->array[a->front];
}
