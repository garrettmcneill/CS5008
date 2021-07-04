#ifndef __MAIN_H
#define __MAIN_H

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab6.h"

// Forward declarations
int cityArrayComparator(const void *p, const void *q);
int findInArray(char **stringArray, int arraySize, char* target);
int * findShortestPath(int ** adjacencies, int adjSize, int startIdx, int endIdx, int *pathLengthPtr);

// Struct and queue for Dijkstra's algorithm
typedef struct City_Struct{
    int cityIdx;
    int parentIdx;
    int minDistance;
    bool processedFlag;
} City;


#endif

