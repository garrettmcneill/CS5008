####################
# Makefile for map Lab 6 Recitation
# June 17, 2021
####################

CC=gcc
CFLAGS=

map: lab6.o main.o
	$(CC) $(CFLAGS) -o map lab6.o main.o

lab6.o: lab6.c lab6.h
	$(CC) $(CFLAGS) -c lab6.c

main.o: main.c lab6.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm map
	rm *.o
