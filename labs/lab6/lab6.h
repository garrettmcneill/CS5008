#ifndef __LAB6_H
#define __LAB6_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**************************************
 *          DEFINITIONS
 *************************************/

typedef int data_t;

/*
 * Singly-linked list node definition.
 */
typedef struct slnode {
    data_t data;
    struct slnode *next;
} slnode_t;

/*
 * Singly-linked list definition.
 */
typedef struct {
    slnode_t *head;
    size_t size;
} sllist_t;


/**************************************
 *         PROVIDED FUNCTIONS
 *************************************/

/*
 * Allocate a new singly-linked list node with the given data value.
 */
slnode_t* malloc_slnode (data_t data);

/*
 * Initialize a singly-linked list
 */
void sllist_init (sllist_t *list);

/*
 * Add an item at the head of the list.
 */
void sllist_addfirst (sllist_t *list, data_t item);

/*
 * Returns true if there is an item equal to the given one in the list.
 */
bool sllist_contains (sllist_t *list, data_t item);

/*
 * Returns the number of items currently in the list.
 */
size_t sllist_size (sllist_t *list);


/**************************************
 *         TO BE IMPLEMENTED
 *         Lab5 Code may be brought in here
 *************************************/

/*
 * Returns the number of items equal to the given one in the list.
 */
size_t sllist_count (sllist_t *list, data_t item);

/*
 * Returns the index of the first item equal to the given item. If no such item
 * is found, returns -1.
 */
int sllist_find (sllist_t *list, data_t item);

/*
 * Clean up the list, freeing all of the list nodes.
 */
void sllist_free (sllist_t *list);

/*
 * Add an item at the tail of the list.
 */
void sllist_addlast (sllist_t *list, data_t item);

/*
 * Returns true if the two lists have the same number of items, and each pair of
 * corresponding items are also equal; false otherwise.
 */
bool sllist_is_equal (sllist_t *list1, sllist_t *list2);

/*
 * Adds an item at the given index in the list.
 */
void sllist_insert (sllist_t *list, data_t item, size_t index);

/*
 * Removed the first item in the list that is equal to the given item. If no
 * such item is found, no changes are made.
 */
void sllist_remove (sllist_t *list, data_t item);

#endif
