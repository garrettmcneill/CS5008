#include <stdio.h>
#include <stdlib.h>

/**
 * Node data structure for singly linked list.
 */
typedef struct node{
    int data;
    struct node* next;
}node_t;

/**
 * Print nodes helper function.
 * @param node
 */
void printNodes(node_t* node){
    node_t* itr = node;

    while( itr != NULL ){
        // print node data
        printf("%d ", itr->data);
        // set to next ...
        itr = itr->next;
    }
    printf("\n");
}

int main(){
    node_t node1;
    node_t node2;
    node_t node3;

    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    printNodes(&node1);

    return 0;


}