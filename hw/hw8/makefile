####################
# Makefile for sortCompare HW8
# Garrett McNeill
# July 28, 2021
####################

CC=gcc
CFLAGS= -lm

sort: shellSort.o shellSort1.o shellSort2.o shellSort3.o shellSort4.o insertionSort.o sortCompare.o
	$(CC) $(CFLAGS) -o sort sortCompare.o shellSort.o shellSort1.o shellSort2.o shellSort3.o insertionSort.o

shellSort.o: shellSort.c shellSort.h
	$(CC) $(CFLAGS) -c shellSort.c

shellSort1.o: shellSort1.c shellSort1.h
	$(CC) $(CFLAGS) -c shellSort1.c

shellSort2.o: shellSort2.c shellSort2.h
	$(CC) $(CFLAGS) -c shellSort2.c

shellSort3.o: shellSort3.c shellSort3.h
	$(CC) $(CFLAGS) -c shellSort3.c

shellSort4.o: shellSort4.c shellSort4.h
	$(CC) $(CFLAGS) -c shellSort4.c

insertionSort.o: insertionSort.c insertionSort.h
	$(CC) $(CFLAGS) -c insertionSort.c

sortCompare.o: sortCompare.c sortCompare.h
	$(CC) $(CFLAGS) -c sortCompare.c

clean:
	rm sort
	rm *.o
