#include <stdio.h>
#include <stdlib.h>

/**
 * Node data structure for singly linked list.
 */
typedef struct node {
    int data;
    struct node *next;
} node_t;

/**
 * Print nodes helper function.
 * @param node
 */
void printNodes(node_t *node) {
    node_t *itr = node;

    while (itr != NULL) {
        // print node data
        printf("%d ", itr->data);
        // set to next ...
        itr = itr->next;
    }
    printf("\n");
}

/**
 * node constructor
 * @param data - int data to store in a node
 * @return a newNode of type node_t
 */
node_t* makeNode(int data) {
    node_t* = newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode = NULL) {
        return NULL;
    }
    newNode->data = data;
    return newNode;
}

/**
 * helper function to remove nodes from memory.
 * @param node - a pointer to a node to free from memory.
 */
void freeNode(node_t *node) {
    if (node == NULL) {
        return;
    }

    free(node);

}


int main() {
    // init nodes
    node_t *node1 = makeNode(1);
    node_t *node2 = makeNode(2);
    node_t *node3 = makeNode(3);

    // traverse
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    // print
    printNodes(&node1);


    // free them from the heap
    freeNode(node1);
    freeNode(node2);
    freeNode(node3);


    return 0;


}