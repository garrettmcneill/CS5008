####################
# Makefile for sortCompare HW8
# July 25, 2021
####################

CC=gcc
CFLAGS= -lm

sortCompare: sortCompare.o
	$(CC) $(CFLAGS) -o sortCompare sortCompare.o shellSort.o insertionSort.o

shellSort.o: shellSort.c shellSort.h
	$(CC) $(CFLAGS) -c shellSort.c

insertionSort.o: insertionSort.c insertionSort.h
	$(CC) $(CFLAGS) -c insertionSort.c insertionSort.h

clean:
	rm sortCompare
	rm *.o
