#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab6.h"

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

        if (tmpInt < 3){
            printf("Line could not be read.\n");
        } else{
            printf("%s %s %d \n", fromCityInput, toCityInput, interCityDistanceInput);
        }

    } while (tmpInt > 0);


    //////// Build an adjacency matrix based on the city.dat datafile ////////



    //////// Create an alphabetized list of cities for selection by the user ////////

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
