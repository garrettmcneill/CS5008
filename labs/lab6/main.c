#include "main.h"

const char inputFileName[] = "city.dat";


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
            if (0 <= fromCityIdx && fromCityIdx < cityArraySize) {
                if (0 <= toCityIdx && toCityIdx < cityArraySize) {
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
        if (fromCityIdx < 0 || fromCityIdx > cityArraySize) {
            printf("You must enter the number associated with one of the cities in the list\n");
            continue;
        } else {
            --fromCityIdx;
        }
        printf("fromcityIdx = %d \n", fromCityIdx);
        if (fromCityIdx < 0) {
            continue;
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
        if (toCityIdx < 1 || toCityIdx > cityArraySize) {
            printf("You must enter the number associated with one of the cities in the list.\n\n");
            continue;
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
        while (shortestPath[idx] >= 0) {
            if (idx == 0) {
                printf("\nPATH CITIES:   %s\n", cityArray[shortestPath[idx]]);
            } else {
                printf("               %s\n", cityArray[shortestPath[idx]]);
            }
            ++idx;
        }
        printf("\n");

        //printf("freeing shortest path\n");
        free(shortestPath);
        shortestPath = NULL;
        //printf("shortest path freed\n");
    } while (fromCityIdx >= 0);


    // clean up array and adjacency matrix
    //printf("freeing city array\n");
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

    //printf("freeing adj matrix\n");
    if (adjMatrix != NULL) {
        for (row = 0; row < cityArraySize; ++row) {
            if (adjMatrix[row] != NULL) {
                free(adjMatrix[row]);
                adjMatrix[row] = NULL;
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
int findInArray(char **stringArray, int arraySize, char *target) {
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
    if (target == NULL) {
        printf("findInArray: target cannot be NULL.\n");
        return -1;
    }

    // check equal or out of range
    compVal = strcmp(target, stringArray[botIdx]);
    if (compVal == 0) {
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

    while (topIdx - botIdx >= 2) {
        midIdx = (topIdx + botIdx) / 2;
        compVal = strcmp(target, stringArray[midIdx]);
        if (compVal == 0) {
            return midIdx;
        } else if (compVal < 0) {
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
 * @param minDistancePtr - a pointer to the integer variable that receives the minimum distance
 * @return an array of the indices of the shortest path
 */
int *findShortestPath(int **adjacencies, int adjSize, int startIdx, int endIdx, int *minDistancePtr) {

    // validate parameters
    if (adjSize < 2) {
        printf("Error: matrix too small");
    }
    if (startIdx < 0 || adjSize <= startIdx) {
        printf("Error: startIdx %d out of range", startIdx);
    }
    if (endIdx < 0 || adjSize <= endIdx) {
        printf("Error: endIdx %d out of range", endIdx);
    }

    // allocate dynamic array for cityQueue
    // dynarray_t* cityQueue = malloc(sizeof(dynarray_t));
    // dynarray_init(cityQueue);

    // allocate & init array for city struct
    City **cityListPtr = calloc(sizeof(City *), adjSize);
    int cityIdx, neighborIdx;
    int unprocessedCityCount, cheapestCityIdx;

    for (cityIdx = 0; cityIdx < adjSize; ++cityIdx) {
        cityListPtr[cityIdx] = malloc(sizeof(City));
        cityListPtr[cityIdx]->cityIdx = cityIdx;
        cityListPtr[cityIdx]->parentIdx = -1;
        cityListPtr[cityIdx]->minDistance = (cityIdx == startIdx) ? 0 : INT_MAX;
        cityListPtr[cityIdx]->processedFlag = false;
    }

    do {
        // count unprocessed cities and find cheapest
        unprocessedCityCount = 0;
        cheapestCityIdx = -1;
        for (cityIdx = 0; cityIdx < adjSize; ++cityIdx) {
            if (!cityListPtr[cityIdx]->processedFlag) {
                ++unprocessedCityCount;
                if (cheapestCityIdx < 0 ||
                    cityListPtr[cityIdx]->minDistance < cityListPtr[cheapestCityIdx]->minDistance) {
                    cheapestCityIdx = cityIdx;
                }
            }
        }
        if (cheapestCityIdx < 0) {
            continue;
        }
        // if we're at the end... end it
        if (cheapestCityIdx == endIdx) {
            break;
        }
        // review neighbors, updating if necessary
        for (neighborIdx = 0; neighborIdx < adjSize; ++neighborIdx) {
            if (!cityListPtr[neighborIdx]->processedFlag && adjacencies[cheapestCityIdx][neighborIdx] > 0) {
                if (cityListPtr[cheapestCityIdx]->minDistance + adjacencies[cheapestCityIdx][neighborIdx]
                    < cityListPtr[neighborIdx]->minDistance) {
                    cityListPtr[neighborIdx]->minDistance = cityListPtr[cheapestCityIdx]->minDistance
                                                            + adjacencies[cheapestCityIdx][neighborIdx];
                    cityListPtr[neighborIdx]->parentIdx = cheapestCityIdx;
                }
            }
        }
        cityListPtr[cheapestCityIdx]->processedFlag = true;

    } while (unprocessedCityCount > 0);

    // calculate final path
    int pathLength = 1;
    cityIdx = endIdx;
    while (cityIdx != startIdx) {
        ++pathLength;
        cityIdx = cityListPtr[cityIdx]->parentIdx;
    }
    int *rVal = calloc(sizeof(int), pathLength + 1 );
    rVal[0] = startIdx; // store first value
    int idx = pathLength -1;
    cityIdx = endIdx;
    // loop to store remaining values
    while (cityIdx != startIdx) {
        rVal[idx] = cityIdx;
        cityIdx = cityListPtr[cityIdx]->parentIdx;
        --idx;
    }
    rVal[pathLength] = -1;
    *minDistancePtr = cityListPtr[endIdx]->minDistance;
    // return array of shortest path cities
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

