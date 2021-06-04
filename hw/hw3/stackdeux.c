#include <stdio.h>
#include <stdlib.h>

// Node data structure
typedef struct NodeStruct {
    int val;
    Node *nextPtr;
} Node;

// Linked "stack" data structure
typedef struct LinkedStackStruct {
    Node *headPtr;
} LinkedStack;


void push(LinkedStack* stackPtr, int d) {
    Node *tmpNode = (Node*)malloc(sizeof(Node));

    // only do if node is not null
    if (tmpNode != NULL) {
        tmpNode->val = d;
        tmpNode->nextPtr = LinkedStack.headPtr;
        LinkedStack.headPtr = tmpNode;
    }
    return;
}


int pop(LinkedStack* stackPtr) {
    if (LinkedStack.headPtr == NULL) {
        return 0;
    }

    // Set current head to the next node, store current head value in temp value, free memory.
    Node *tmpNodePtr = LinkedStack.headPtr;
    int tmpVal = tmpNodePtr->val;
    LinkedStack.headPtr = tmpNodePtr->nextPtr;

    // free it
    free(tmpNodePtr);

    return tmpVal;
}


// Conditional expression to check if the head is null.
void isEmpty(LinkedStack* stackPtr) {
    return ( struct LinkedStack.headPtr == NULL )
    ? 1
    : 0;
}


int main() {

    LinkedStack* myStackPtr = (LinkedStack*)malloc(sizeof(LinkedStack));
    myStackPtr->headPtr = NULL;

    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    push(myStackPtr,1);
    push(myStackPtr,2);
    push(myStackPtr,3);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    push(myStackPtr,4);
    push(myStackPtr,5);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    push(myStackPtr,6);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);
    rVal = pop(myStackPtr);
    printf("Pop Return value = %d\n", rVal);

    return 0;
}