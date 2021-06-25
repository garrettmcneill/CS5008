#include "lab6.h"

// allocate & init singly linked list
sllist_t* malloc_sllist(){

    sllist_t* list = (sllist_t*) malloc(sizeof(sllist_t));

    if (list == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for linked list.");
        exit(EXIT_FAILURE);
    }

    // take list and init it
    sllist_init(list);

    return list;
}



/**************************************
 *         PROVIDED FUNCTIONS
 *************************************/

slnode_t* malloc_slnode(data_t data) {

    slnode_t *node = (slnode_t*)malloc(sizeof(slnode_t));

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

    int itemLen = strlen(item);
    char* newPtr;

    if (itemLen > 0){
        newPtr = malloc(itemLen+1);
        strncpy(newPtr, item, itemLen);
        newPtr[itemLen] = '\0';
    } else{
        newPtr = NULL;
    }

    slnode_t *new_node = malloc_slnode(newPtr);   // allocate new node

    if (list->head != NULL) {                   // non-empty list:
        new_node->next = list->head;            //   set the new node's next ptr
    }
    list->head = new_node;                      // set the list head
    list->size++;                               // increment the size tracker
}

bool sllist_contains (sllist_t *list, data_t item) {

    slnode_t *n;

    // iterate over the linked list, looking for 'item'
    for (n = list->head; n != NULL; n = n->next) {
        if (strcmp(n->data, item) == 0) {  // switched this to string compare -G
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
 *         Lab5 Code may be brought in here
 *************************************/

size_t sllist_count (sllist_t *list, data_t item) {

    return 0;
}

int sllist_find (sllist_t *list, data_t item) {

    return -1;
}

void sllist_free (sllist_t *list) {

}

void sllist_addlast (sllist_t *list, data_t item) {

}

bool sllist_is_equal (sllist_t *list1, sllist_t *list2) {

    return false;
}

void sllist_insert (sllist_t *list, data_t item, size_t index) {

}

void sllist_remove (sllist_t *list, data_t item) {

}

char **sllist_to_array(sllist_t *list){
    char ** charPtrArray = NULL;
    if(list == NULL){
        printf("LIST IS NULL.");
        return charPtrArray;
    }

    // determine length of list
    int listlen = sllist_size(list) + 1;


    printf("list len = %d\n", listlen);


    // allocate array of char pointers
    charPtrArray = calloc(sizeof(char*), listlen);
    if (charPtrArray == NULL){
        printf("UNABLE TO ALLOCATE ARRAY.\n");
        return charPtrArray;
    }
    charPtrArray[listlen] = NULL;


    printf("array allocated..\n");


    // copy data pointers to array
    slnode_t* nextNode = list->head;
    if (nextNode != NULL) {
        int idx = 0;
        do{
            charPtrArray[idx] = nextNode->data;
            printf("copying string idx: %d, [%s]\n", idx, charPtrArray[idx]);
            nextNode = nextNode->next;
            ++idx;
        }while(nextNode != NULL);
    }else{
        printf("LIST IS EMPTY.");
    }

    // free linked list, but not data
    do{
        if(list->head != NULL){
            nextNode = list->head;
            list->head = list->head->next;
            free(nextNode);
        }
    }while(list->head != NULL);
    free(list);

    return charPtrArray;
}


