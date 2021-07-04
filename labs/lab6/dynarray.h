#ifndef __DYNARRAY_H
#define __DYNARRAY_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

/**************************************
 * Dynamic Arrays (With Stack and
 * Queue ADTs implemented)
 *************************************/

typedef struct {
    data_t *array;
    size_t capacity;
    size_t size;
    size_t front;
} dynarray_t;

/* dynamic array operations */
void   dynarray_init(dynarray_t *a);
void   dynarray_expand(dynarray_t *a, size_t capacity);
size_t dynarray_size(dynarray_t *a);
size_t dynarray_is_empty(dynarray_t *a);
void   dynarray_free(dynarray_t *a);

/* stack operations */
void   dynarray_push(dynarray_t *a, data_t item);
data_t dynarray_pop(dynarray_t *a);
data_t dynarray_top(dynarray_t *a);

/* queue operations */
void   dynarray_enqueue(dynarray_t *a, data_t item);
data_t dynarray_dequeue(dynarray_t *a);
data_t dynarray_front(dynarray_t *a);

#endif
