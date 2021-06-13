####################
# Makefile for queue Lab 5 Recitation
# June 10, 2021
####################

CC=gcc
CFLAGS=

queue: lab5.o dynarray.o main.o
	$(CC) $(CFLAGS) -o queue lab5.o dynarray.o main.o

lab5.o: lab5.c lab5.h dynarray.h
	$(CC) $(CFLAGS) -c lab5.c

dynarray.o: dynarray.c dynarray.h
	$(CC) $(CFLAGS) -c dynarray.c

main.o: main.c lab5.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm queue
	rm *.o
