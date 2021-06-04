#include <stdio.h>

typedef struct NodeStruct {
    int val;
    int *nextPtr = NULL;
} Node;

struct LinkedStack {
    Node *headPtr = NULL;
};


void push(int d) {
    Node *tmpNode = (Node *)malloc(sizeof(Node));

    // only do if node is not null
    if (tmpNode != NULL) {
        tmpNode->val = d;
        tmpNode->nextPtr = LinkedStack.headPtr;
        LinkedStack.headPtr = tmpNode;
    }
    return;
}


int pop() {
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
void isEmpty() {
    return ( struct LinkedStack.headPtr == NULL )
    ? 1
    : 0;
}


int main() {

    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    push(1);
    push(2);
    push(3);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    push(4);
    push(5);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    push(6);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);

    return 0;
}