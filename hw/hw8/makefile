####################
# Makefile for sortCompare HW8
# July 25, 2021
####################

CC=gcc
CFLAGS= -lm

sort: shellSort.o shellSort1.o shellSort2.o insertionSort.o sortCompare.o
	$(CC) $(CFLAGS) -o sort sortCompare.o shellSort.o shellSort1.o shellSort2.o insertionSort.o

shellSort.o: shellSort.c shellSort.h
	$(CC) $(CFLAGS) -c shellSort.c

shellSort1.o: shellSort1.c shellSort1.h
	$(CC) $(CFLAGS) -c shellSort1.c

shellSort2.o: shellSort2.c shellSort2.h
	$(CC) $(CFLAGS) -c shellSort2.c

insertionSort.o: insertionSort.c insertionSort.h
	$(CC) $(CFLAGS) -c insertionSort.c

sortCompare.o: sortCompare.c sortCompare.h
	$(CC) $(CFLAGS) -c sortCompare.c

clean:
	rm sort
	rm *.o
