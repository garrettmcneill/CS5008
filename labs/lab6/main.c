#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab6.h"

const char inputFileName[] = "city.dat";

// Forward declarations
int cityArrayComparator(const void *p, const void *q);
int findInArray(char **stringArray, int arraySize, char* target);
int * findShortestPath(int ** adjacencies, int adjSize, int startIdx, int endIdx, int *pathLengthPtr);


int main() {

    //////// Read data from datafile city.dat ////////

    sllist_t *cityListPtr = malloc_sllist();

    char fromCityInput[25], toCityInput[25];
    int interCityDistanceInput;
    int tmpInt;

    if (cityListPtr == NULL) {
        printf("cityList allocation failed!\n");
        exit(-1);
    }

    // open input file
    FILE *cityFilePtr = fopen(inputFileName, "r");
    // test if file exists
    if (cityFilePtr == NULL) {
        printf("File not found!\n");
        exit(-1);
    }

    // read file, adding each city to linked list
    do {
        tmpInt = fscanf(cityFilePtr, "%s %s %d", fromCityInput, toCityInput, &interCityDistanceInput);
        if (tmpInt > 0 && tmpInt < 3) {
            printf("Line could not be read.\n");
        } else {
            if (strlen(fromCityInput) > 0) {
                // if fromCity not in list, add it
                if (!sllist_contains(cityListPtr, fromCityInput)) {
                    sllist_addfirst(cityListPtr, fromCityInput);
                }
            }
            if (strlen(toCityInput) > 0) {
                // if fromCity not in list, add it
                if (!sllist_contains(cityListPtr, toCityInput)) {
                    sllist_addfirst(cityListPtr, toCityInput);
                }
            }
        }
    } while (tmpInt > 0);

    // Close the file
    fclose(cityFilePtr);
    cityFilePtr = NULL;

    //////// Create an alphabetized list of cities for selection by the user ////////
    char **cityArray = sllist_to_array(cityListPtr);
    cityListPtr = NULL;
    int idx = 0;
    int cityArraySize;

    // determine size of array
    for (cityArraySize = 0; cityArray[cityArraySize] != NULL; ++cityArraySize) {
        // intentionally left empty
        // printf("trying city array size = %d\n", cityArraySize);
    }

    qsort((void *) cityArray, cityArraySize, sizeof(char *), cityArrayComparator);


    //////// Build an adjacency matrix based on the city.dat datafile ////////
    int row, col;
    int fromCityIdx, toCityIdx;

    // allocate adjacency matrix
    int **adjMatrix = calloc(sizeof(int *), cityArraySize);
    for (row = 0; row < cityArraySize; ++row) {
        adjMatrix[row] = calloc(sizeof(int), cityArraySize);
    }

    // init matrix values to 0
    for (row = 0; row < cityArraySize; ++row) {
        for (col = 0; col < cityArraySize; ++col) {
            adjMatrix[row][col] = 0;
        }
    }

    // open input file
    cityFilePtr = fopen(inputFileName, "r");

    // test if file exists
    if (cityFilePtr == NULL) {
        printf("Input file not found!\n");
        exit(-1);
    }

    // read file, adding each city pair to adjacency matrix
    do {
        tmpInt = fscanf(cityFilePtr, "%s %s %d", fromCityInput, toCityInput, &interCityDistanceInput);
        if (tmpInt > 0 && tmpInt < 3) {
            printf("Line could not be read.\n");
        } else {
            // determine from city index (row)
            fromCityIdx = findInArray(cityArray, cityArraySize, fromCityInput);

            // determine to city index (col)
            toCityIdx = findInArray(cityArray, cityArraySize, toCityInput);

            // store interCityDistance in adjacency[row][col]
            if (0 <= fromCityIdx && fromCityIdx < cityArraySize){
                if (0 <= toCityIdx && toCityIdx < cityArraySize){
                    adjMatrix[fromCityIdx][toCityIdx] = interCityDistanceInput;
                } else {
                    printf("To city %s could not be found \n", toCityInput);
                }
            } else {
                printf("From city %s could not be found \n", fromCityInput);
            }
        }
    } while (tmpInt > 0);

    // Close the file
    fclose(cityFilePtr);
    cityFilePtr = NULL;

    // declarations before loop
    int shortestDistance = 100;
    int *shortestPath;

    do {
        // display list of cities a->z and prompt user for origin city
        // if 0... quit
        printf("Please select an origin city\n");
        printf("Enter a number associated with one of the cities below: \n");
        for (idx = 0; idx < cityArraySize; ++idx) {
            printf("%15s  ---  %2d\n", cityArray[idx], idx + 1);
        }
        printf("\n TO QUIT ENTER -- 0 \n\n");
        scanf("%d", &fromCityIdx);
        if ( fromCityIdx < 1 || fromCityIdx > cityArraySize ){
            printf("You must enter the number associated with one of the cities in the list\n");
            break;
        } else {
            --fromCityIdx;
        }

        // display list of cities minus origin city and get destination city
        printf("Please select a destination city\n");
        printf("Enter a number associated with one of the cities below: \n");
        for (idx = 0; idx < cityArraySize; ++idx) {
            if (idx != fromCityIdx) {
                printf("%15s  ---  %2d\n", cityArray[idx], idx + 1);
            }
        }
        scanf("%d", &toCityIdx);
        if ( toCityIdx < 1 || toCityIdx > cityArraySize ){
            printf("You must enter the number associated with one of the cities in the list\n");
            break;
        } else {
            --toCityIdx;
        }

        // apply Dijkstra's algorithm to find shortest path & distance
        shortestPath = findShortestPath(adjMatrix, cityArraySize, fromCityIdx, toCityIdx, &shortestDistance);

        // print results of Dijkstra's
        printf("\nORIGIN:        %s\n", cityArray[fromCityIdx]);
        printf("DESTINATION:   %s\n\n", cityArray[toCityIdx]);
        printf("LENGTH:        %d\n", shortestDistance);
        idx = 0;
        while(shortestPath[idx] >= 0) {
            if (idx == 0){
                printf("\nPATH CITIES:   %s\n", cityArray[shortestPath[idx]]);
            } else {
                printf("               %s\n", cityArray[shortestPath[idx]]);
            }
            ++idx;
        }
        printf("\n");

        //free(shortestPath);
       // shortestPath = NULL;
    } while( fromCityIdx > 0);


    // clean up array and adjacency matrix
    if (cityArray != NULL) {
        for (row = 0; row < cityArraySize; ++row) {
            if (cityArray[row] != NULL) {
                free(cityArray[row]);
                cityArray[row] = NULL;
            }
        }
        free(cityArray);
        cityArray = NULL;
    }
    if (adjMatrix != NULL) {
        for (row = 0; row < cityArraySize; ++row) {
            if (adjMatrix[row] != NULL) {
                free(adjMatrix[row]);
                adjMatrix = NULL;
            }
        }
        free(adjMatrix);
        adjMatrix = NULL;
    }

    return EXIT_SUCCESS;
}



/* Binary search to find a target in a sorted array of strings
 *  stringArray - a list of strings a->z
 *  arraySize - the number of entries in the array
 *  target - the string to be found
 * Returns the index of the matching entry, or 0.
 * */
int findInArray(char **stringArray, int arraySize, char* target) {
    int botIdx = 0;
    int topIdx = arraySize - 1;
    int midIdx, compVal;

    // check parameters
    if (stringArray == NULL) {
        printf("findInArray: stringArray is NULL.\n");
        return -1;
    }
    if (arraySize < 1) {
        printf("findInArray: array size must be > 1.\n");
        return -1;
    }
    if (target == NULL){
        printf("findInArray: target cannot be NULL.\n");
        return -1;
    }

    // check equal or out of range
    compVal = strcmp(target, stringArray[botIdx]);
    if (compVal == 0){
        return botIdx;
    } else if (compVal < 0) {
        printf("findInArray: target out of range");
        return -1;
    }
    compVal = strcmp(target, stringArray[topIdx]);
    if (compVal == 0) {
        return topIdx;
    } else if (compVal > 0) {
        printf("findInArray: target out of range");
        return -1;
    }

    while(topIdx - botIdx >= 2){
        midIdx = (topIdx + botIdx) / 2;
        compVal = strcmp(target, stringArray[midIdx]);
        if(compVal == 0){
            return midIdx;
        } else if (compVal < 0){
            topIdx = midIdx;
        } else {
            botIdx = midIdx;
        }
    }
    return -1;
}


/**
 * Apply Dijkstra's algorithm to find shortest path from the start to the end.
 * @param adjacencies - square array of distances
 * @param adjSize - size of the adjacency matrix
 * @param startIdx - the starting index
 * @param endIdx - the ending index
 * @param pathLengthPtr - a pointer to the integer variable that receives the shortest path length
 * @return an array of the indices of the shortest path
 */
int * findShortestPath(int ** adjacencies, int adjSize, int startIdx, int endIdx, int *pathLengthPtr){
    // stub
    int * rVal = calloc(sizeof(int), 3);
    rVal[0] = startIdx;
    rVal[1] = endIdx;
    rVal[2] = -1;
    *pathLengthPtr = 20;
    return rVal;
}

// cityArrayComparator
int cityArrayComparator(const void *p, const void *q) {
    char **l = (char **) p;
    char **r = (char **) q;
    int rVal = strcmp(*l, *r);
    return rVal;
}






//Display the cities from which to select using a number that your
//program assigns from the alphabetized list of cities that is
//dynamically created from your city.dat file.  Example:
//     Please select an origin city
//     Enter a number associated with one of the cities below:
//     Amsterdam    ---  1
//     Belgrade     ---  2
//     Bern         ---  3
//     Genoa        ---  4
//     Hamburg      ---  5
//     Lisbon       ---  6
//     Madrid       ---  7
//     Munich       ---  8
//     Naples       ---  9
//     Paris        --- 10
//     Warsaw       --- 11
//
//     TO QUIT ENTER --  0
//
//     $>

//Have the user select an origin city, displaying the above list

//Have the user select a destination city, removing the origin
//city from the list

//Apply Dijkstra's Algorithm to determine the optimal (shortest) path

//Report three items:
//     1. the names of the two cities, such as:
//          ORIGIN:      Lisbon
//          DESTINATION: Warsaw
//     2. the length of the optimal path, such as:
//          LENGTH:      1629
//     3. the list of the cities visited along the optimal path, like:
//          PATH CITIES: Lisbon
//                       Madrid
//                       Genoa
//                       Trieste
//                       Vienna
//                       Warsaw

//Continue to ask for two cities to map until the user selects 0

