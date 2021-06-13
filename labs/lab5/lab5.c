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
    int halfLen, baseLen, idx;

    printf("is palindrome: textlen=%d \n", textLen);
    printf("is palindrome: text=%s \n", text);

    // create dynamic array
    printf("creating dynamic array \n");

    dynarray_t* queueArray = malloc(sizeof(dynarray_t));
    dynarray_t* stackArray = malloc(sizeof(dynarray_t));
    dynarray_init(queueArray);
    dynarray_init(stackArray);

    // copy text into arrays
    printf("copying text into arrays \n");
    halfLen = textLen/2;
    for (idx = 0; idx < halfLen; ++idx) {
        dynarray_enqueue(queueArray, (data_t)text[idx]);
    }
    baseLen = halfLen + textLen %2 + 1;
    for (idx = 0; idx < halfLen; ++idx) {
        dynarray_push(stackArray, (data_t)text[baseLen+idx]);
    }

    // check for palindrome
    printf("checking for palindrome \n");

    bool palindromeFlag = true;
    data_t charFront, charBack;

    while (dynarray_size(queueArray) > 1) {
        charFront = dynarray_dequeue(queueArray);
        charBack = dynarray_pop(stackArray);
        printf("isPalindrome: front=%d, back=%d \n", charFront, charBack);
        if (charFront != charBack) {
            palindromeFlag = false;
            break;
        }
    }

    printf("cleaning up memory \n");

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

