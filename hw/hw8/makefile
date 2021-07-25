####################
# Makefile for sortCompare HW8
# July 25, 2021
####################

CC=gcc
CFLAGS=

sortCompare: sortCompare.o
	$(CC) $(CFLAGS) -o sortCompare sortCompare.o shellSort.o insertionSort.o

clean:
	rm sortCompare
	rm *.o
