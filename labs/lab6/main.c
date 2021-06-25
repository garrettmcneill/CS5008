#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab6.h"

/*
 * Forward declaration for city names. Included in .c for local use only..
 */
int cityArrayComparator(const void *p, const void *q);

int main() {

	//////// Read data from datafile city.dat ////////

    sllist_t* cityListPtr = malloc_sllist();

    char fromCityInput[25], toCityInput[25];
    int interCityDistanceInput;
    int tmpInt;

    if (cityListPtr == NULL){
        printf("cityList allocation failed!\n");
        exit(-1);
    }

    // open file
    FILE *cityFilePtr  = fopen("city.dat", "r");
    // test if file exists
    if (cityFilePtr == NULL ){
        printf("File not found!\n");
        exit(-1);
    }

    // read file, adding each city to linked list
    do {
        tmpInt = fscanf(cityFilePtr, "%s %s %d", fromCityInput, toCityInput, &interCityDistanceInput);

        if (tmpInt > 0 && tmpInt < 3){
            printf("Line could not be read.\n");
        } else {
            if(strlen(fromCityInput) > 0){
                // if fromCity not in list, add it
                if( ! sllist_contains(cityListPtr, fromCityInput ) ){
                    sllist_addfirst(cityListPtr, fromCityInput);
                }
            }
            if(strlen(toCityInput) > 0){
                // if fromCity not in list, add it
                if( ! sllist_contains(cityListPtr, toCityInput ) ){
                    sllist_addfirst(cityListPtr, toCityInput);
                }
            }

            printf("%s %s %d \n", fromCityInput, toCityInput, interCityDistanceInput);
        }

    } while (tmpInt > 0);


    //////// Create an alphabetized list of cities for selection by the user ////////
    char ** cityArray = sllist_to_array(cityListPtr);
    printf("slist converted to array...\n");
    cityListPtr = NULL;
    int idx = 0;
    int cityArraySize;

    // determine size of array
    for (cityArraySize = 0; cityArray[cityArraySize] != NULL; ++cityArraySize){
        printf("trying city array size = %d\n", cityArraySize);
    }



    printf("array size = %d\n", cityArraySize);


    qsort((void*)cityArray, cityArraySize, sizeof(char *), cityArrayComparator);

    printf("array sorted\n");

    // print sorted array
    for (idx = 0; idx < cityArraySize; ++idx){
        printf("%15s  ---  %2d\n", cityArray[idx], idx);
    }


    //////// Build an adjacency matrix based on the city.dat datafile ////////




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


    return EXIT_SUCCESS;
}

// cityArrayComparator
int cityArrayComparator(const void *p, const void *q)
{
    char* l = (char  *)p;
    char* r = (char  *)q;
    return (strcmp(l, r));
}