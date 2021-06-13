#include "lab5.h"

/**************************************
 *         PROVIDED FUNCTIONS
 *************************************/

slnode_t *malloc_slnode(data_t data) {

    slnode_t *node = (slnode_t *) malloc(sizeof(slnode_t));

    if (node == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for link list node.");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;

    return node;
}

void sllist_init(sllist_t *list) {

    list->head = NULL;
    list->size = 0;
}

void sllist_addfirst(sllist_t *list, data_t item) {

    slnode_t *new_node = malloc_slnode(item);   // allocate new node

    if (list->head != NULL) {                   // non-empty list:
        new_node->next = list->head;            //   set the new node's next ptr
    }
    list->head = new_node;                      // set the list head
    list->size++;                               // increment the size tracker
}

bool sllist_contains(sllist_t *list, data_t item) {

    slnode_t *n;

    // iterate over the linked list, looking for 'item'
    for (n = list->head; n != NULL; n = n->next) {
        if (n->data == item) {
            return true;
        }
    }

    return false;
}

size_t sllist_size(sllist_t *list) {

    return list->size;
}


/**************************************
 *         TO BE IMPLEMENTED
 *************************************/

bool is_palindrome(char *text) {

    int textLen = strlen(text);
    int idx;

    // create dynamic array
    dynarray_t* wordArray = malloc(sizeof(dynarray_t));
    dynarray_init(wordArray);
    dynarray_expand(wordArray, textLen);

    // copy text into array
    for (idx = 0, idx < textLen; ++idx;) {
        dynarray_push(wordArray, text[idx]);
    }

    // check for palindrome
    bool palindromeFlag = true;
    data_t charFront, charBack;

    while (dynarray_size(wordArray) > 1) {
        charFront = dynarray_dequeue(wordArray);
        charBack = dynarray_pop(wordArray);
        if (charFront != charBack) {
            palindromeFlag = false;
            break;
        }
    }
    while(!dynarray_is_empty(wordArray)){
        dynarray_pop(wordArray);
    }
    free(wordArray);
    return palindromeFlag;
}

size_t sllist_count(sllist_t *list, data_t item) {

    return 0;
}

int sllist_find(sllist_t *list, data_t item) {

    return -1;
}

void sllist_free(sllist_t *list) {

}

void sllist_addlast(sllist_t *list, data_t item) {

}

bool sllist_is_equal(sllist_t *list1, sllist_t *list2) {

    return false;
}

void sllist_insert(sllist_t *list, data_t item, size_t index) {

}

void sllist_remove(sllist_t *list, data_t item) {

}

