#include <stdio.h>

// declare stack array and top idx
int stackArray[100];
int top = -1;

// is empty
int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// trying a conditional expression
int isEmpty2() {
    return (top == -1)
           ? 1
           : 0;
}

int push(int v) {
    // check
    if (top >= 99) {
        printf("STACK OVERFLOW!");
        return 0;
    }
    // increment top
    ++top;
    stackArray[top] = v;
    return 1;
}

int pop() {
    // empty check
    if (top <= -1) {
        printf("STACK IS EMPTY!");
        return 0;
    }

    // store top in tmp var
    int topVal = stackArray[top];

    // decrement top
    --top;

    return topVal;
}

int main(){
    int rVal;
    rVal = pop();
    printf("Pop Return value = %d\n", rVal);
    push(1);
    push(2);
    push(3);
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
}