#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 200

// ========================== NODE/TREE DEFINITIONS ==========================
// define node structure
typedef struct nd {
    int data;
    struct nd* left;
    struct nd* right;
} node;

// "new" function to create a node, set data value to d and children to NULL
node* newNode(int d) {
    node* np;
    np = (node*)malloc(sizeof(node));
    if (np != NULL) {
        np->data = d;
        np->left = NULL;
        np->right = NULL;
    }
    return(np);
}

// declare root of our binary tree
node* rootp = NULL;


// ========================== STRING DEFINITIONS ==========================
// dna is a string defining the content and structure of the tree in pre-order with '\n' for NULL pointers
char dna[MAX_STRING] = "ABDHP\n\nQ\n\nIR\n\nS\n\nEJT\n\nU\n\nKV\n\nW\n\nCFL\n\nMX\n\nY\n\nGN\nZ\n\nO\n\n";

// remove the first character from string s and return it, \x01 will be an error code if string is empty
char getFirstChar(char* s) {
    char c;
    if (strlen(s) > 0) {
        // copy the first character
        c = s[0];

        // remove the first charcter from the string
        memmove(s, s+1, strlen(s));
    } else {
        // empty string, set error code
        c = '\x01';
    }

    return c;
}

// ========================== MAIN RECURSIVE FUNCTION TO BUILD TREE  ==========================
// using the instruction in string s, insert the defined nodes into tree pointed to by rp
void insertNode (node* rp, char* s) {
    char c;   // temporary character

    // we assume that rp points to an existing node and
    // we are going to add its two children based on the next two instructions in s
    if (rp != NULL) {

        // if instruction string is not empty then add a new node to the left
        if (strlen(s) >  0) {
            // get the first character of the string which is our "instruction"
            c = getFirstChar(s);

            if (c == '\x01') {
                printf("ILLEGAL CHARACTER IN INSTRUCTION STRING\n");
            }

            // if instruction does not tell us to insert null, create a new node and add it as left child, recurse
            if (c != '\n') {
                rp->left = newNode(c);
                insertNode(rp->left, s);
            }
        }

        // if instruction string is not empty then add a new node to the right
        if (strlen(s) >  0) {
            // get the first character of the string which is our "instruction"
            c = getFirstChar(s);

            if (c == '\x01') {
                printf("ILLEGAL CHARACTER IN INSTRUCTION STRING\n");
            }

            // if instruction does not tell us to insert null, create a new node and add it as right child, recurse
            if (c != '\n') {
                rp->right = newNode(c);
                insertNode(rp->right, s);
            }
        }
    }
    return;
}

// ========================== BEGIN INSERT FUNCTION DEFS TO WALK TREE ==========================
// define 3 functions - preorder, inorder, postorder to walk tree, printing out data (char)
// associated with each node visited:
void preorder (node* np) {}

void inorder (node* np) {}

void postorder (node* np) {}


// ========================== END INSERT FUNCTIONS HERE TO WALK TREE ==========================




// ========================== MAIN PROGRAM  ==========================
int main() {
    char c; // temporary character variable

    // prime the pump - add the first node to the tree and then recursively call on children
    rootp = NULL;

    // if instruction string is not empty then create root node
    if (strlen(dna) >  0) {
        // get the first character of the string which is our "instruction"
        c = getFirstChar(dna);

        if (c == '\x01') {
            printf("ILLEGAL CHARACTER IN INSTRUCTION STRING\n");
        }

        // if instruction does not tell us to insert null, create a new node and add it as left child, recurse
        if (c != '\n') {
            rootp = newNode(c);
            insertNode(rootp, dna);
        }
    }

    // ========================== MAIN PROG CODE TO CALL WALK FUNCTONS  ==========================

    printf("PREORDER:\n");
    preorder(rootp);
    printf("\n\n");

    printf("INORDER:\n");
    inorder(rootp);
    printf("\n\n");

    printf("POSTORDER:\n");
    postorder(rootp);
    printf("\n\n");

    return 0;
}
