#include "trie1.h"

// Define the character size
#define CHAR_SIZE 26


// Data structure to store a Trie node
struct Trie {
    struct Trie *character[CHAR_SIZE];
    int isLeaf;            // 1 when the node is a leaf node
};

// Function that returns a new Trie node
struct Trie *getNewTrieNode() {
    int i;
    struct Trie *node = (struct Trie *) malloc(sizeof(struct Trie));
    node->isLeaf = 0;

    for (i = 0; i < CHAR_SIZE; i++) {
        node->character[i] = NULL;
    }

    return node;
}

// Iterative function to insert a string into a Trie
void insert(struct Trie *head, char *str) {
    // start from the root node
    struct Trie *curr = head;
    while (*str) {
        // create a new node if the path doesn't exist
        if (curr->character[*str - 'a'] == NULL) {
            curr->character[*str - 'a'] = getNewTrieNode();
        }

        // go to the next node
        curr = curr->character[*str - 'a'];

        // move to the next character
        str++;
    }

    // mark the current node as a leaf
    curr->isLeaf = 1;
}

// Iterative function to search a string in a Trie. It returns 1
// if the string is found in the Trie; otherwise, it returns 0.
int search(struct Trie *head, char *str) {
    // return 0 if Trie is empty
    if (head == NULL) {
        return 0;
    }

    struct Trie *curr = head;
    while (*str) {
        // go to the next node
        curr = curr->character[*str - 'a'];

        // if the string is invalid (reached end of a path in the Trie)
        if (curr == NULL) {
            return 0;
        }

        // move to the next character
        str++;
    }

    // return 1 if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}

// Returns 1 if a given Trie node has any children
int hasChildren(struct Trie *curr) {
    int i;

    for (i = 0; i < CHAR_SIZE; i++) {
        if (curr->character[i]) {
            return 1;    // child found
        }
    }

    return 0;
}

// Recursive function to delete a string from a Trie
int deletion(struct Trie **curr, char *str) {
    // return 0 if Trie is empty
    if (*curr == NULL) {
        return 0;
    }

    // if the end of the string is not reached
    if (*str) {
        // recur for the node corresponding to the next character in
        // the string and if it returns 1, delete the current node
        // (if it is non-leaf)
        if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
            deletion(&((*curr)->character[*str - 'a']), str + 1) &&
            (*curr)->isLeaf == 0) {
            if (!hasChildren(*curr)) {
                free(*curr);
                (*curr) = NULL;
                return 1;
            } else {
                return 0;
            }
        }
    }

    // if the end of the string is reached
    if (*str == '\0' && (*curr)->isLeaf) {
        // if the current node is leaf node and has no children
        if (!hasChildren(*curr)) {
            free(*curr);    // delete the current node
            (*curr) = NULL;
            return 1;    // delete the non-leaf parent nodes
        }

            // if the current node is a leaf node and has children
        else {
            // mark the current node as non-leaf (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0;    // don't delete its parent nodes
        }
    }

    return 0;
}

// Trie implementation in C --- Insertion, Searching, and Deletion
int main(int argc, char *argv[]) {

    // Variables
    struct Trie *head = getNewTrieNode();

    char *fileNamePtr = NULL;
    FILE *filePtr;
    char inputBuff[200];
    char *searchWord = NULL;

    int wordCount = 0;
    int tmpInt;
    int retn;


    printf("\n\n- - - Trie Word Lookup Program - - -\n");
    printf("- - - Garrett McNeill | NEU 21 - - -\n");

    // cmd line argument validation
    if (argc < 2) {
        printf("Not enough arguments passed at the execution of the program.\n");
        return -1;
    }

    // copy file name to fileNamePtr
    fileNamePtr = malloc(strlen(argv[1]) + 1);
    strncpy(fileNamePtr, argv[1], strlen(argv[1]) + 1);


    //////// Read data from file ////////

    // open input file
    filePtr = fopen(fileNamePtr, "r");
    // test if file exists
    if (filePtr == NULL) {
        printf("File not found!\n");
        exit(-1);
    }

    // read file, adding each word to trie
    do {
        tmpInt = fscanf(filePtr, "%s", inputBuff); // read words 1 by 1
        if (tmpInt == 1) {
            insert(head, inputBuff); // transfer word from input buffer to trie
            ++wordCount;
        } else if (tmpInt > 0) {
            printf("Line could not be read.\n");
        }
    } while (tmpInt > 0);

    // Close the file
    fclose(filePtr);
    filePtr = NULL;


    // read out number of words loaded
    printf("Filename: %s \n", fileNamePtr);
    printf("Number of words loaded: %d \n\n", wordCount);


    do {

        // Prompt user for a search word
        fputs("Input a word that you would like to search for (QUIT for done): ", stdout);
        retn = scanf(" %199[^\n]", inputBuff);

        if (retn = 0){
            printf("You did not input a word! Try again. \n");
            continue;
        }

        // check to see if user wants to quit
        if ((strcmp(inputBuff, "QUIT") == 0) || (strcmp(inputBuff, "quit") == 0)) {
            printf("\n\nend program \n\n");
            return 0;

        } else {
            int rVal;
            rVal = search(head, inputBuff);

            if (rVal == 1) {
                printf("Success! %s was found in %s \n\n", inputBuff, fileNamePtr);
            } else{
                printf("Oh no! %s was not found in %s \n\n", inputBuff, fileNamePtr);
            }

        }

    } while ((strcmp(inputBuff, "quit") != 0) && (strcmp(inputBuff, "QUIT") != 0));

    /*

    insert(head, "hello");
    printf("%d ", search(head, "hello"));    // print 1

    insert(head, "helloworld");
    printf("%d ", search(head, "helloworld"));    // print 1

    printf("%d ", search(head, "helll"));    // print 0 (Not present)

    insert(head, "hell");
    printf("%d ", search(head, "hell"));        // print 1

    insert(head, "h");
    printf("%d \n", search(head, "h"));        // print 1 + newline

    deletion(&head, "hello");
    printf("%d ", search(head, "hello"));    // print 0 (hello deleted)
    printf("%d ", search(head, "helloworld"));    // print 1
    printf("%d \n", search(head, "hell"));    // print 1 + newline

    deletion(&head, "h");
    printf("%d ", search(head, "h"));        // print 0 (h deleted)
    printf("%d ", search(head, "hell"));        // print 1
    printf("%d\n", search(head, "helloworld"));    // print 1 + newline

    deletion(&head, "helloworld");
    printf("%d ", search(head, "helloworld"));    // print 0
    printf("%d ", search(head, "hell"));        // print 1

    deletion(&head, "hell");
    printf("%d\n", search(head, "hell"));    // print 0 + newline

    if (head == NULL) {
        printf("Trie empty!!\n");        // Trie is empty now
    }

    printf("%d ", search(head, "hell"));        // print 0

     */
    return 0;
}
