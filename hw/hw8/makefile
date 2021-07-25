####################
# Makefile for sortCompare HW8
# July 25, 2021
####################

CC=gcc
CFLAGS= -lm

sort: shellSort.o insertionSort.o sortCompare.o
	$(CC) $(CFLAGS) -o sort sortCompare.o shellSort.o insertionSort.o

shellSort.o: shellSort.c shellSort.h
	$(CC) $(CFLAGS) -c shellSort.c

insertionSort.o: insertionSort.c insertionSort.h
	$(CC) $(CFLAGS) -c insertionSort.c

sortCompare.o: sortCompare.c sortCompare.h
	$(CC) $(CFLAGS) -c sortCompare.c

clean:
	rm sort
	rm *.o
