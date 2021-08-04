####################
# Makefile for Lecture 10 
# July 21, 2021
####################

CC=gcc
CFLAGS= -lpthread

#
# t3 makefile commands
#
t3: thread3.o
	$(CC) $(CFLAGS) -o t3 thread3.o

thread3.o: thread3.c
	$(CC) $(CFLAGS) -c thread3.c


clean:
	rm t3
