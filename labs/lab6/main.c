#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab6.h"

int main() {

	//Read data from datafile city.dat
	
	//Build an adjacency matrix based on the city.dat datafile
	
	//Create an alphabetized list of cities for selection by the user

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
