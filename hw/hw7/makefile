####################
# Makefile for mfib HW7
# June 23, 2021
####################

CC=gcc
CFLAGS=

fib: fib.o
	$(CC) $(CFLAGS) -o fib fib.o

fib.o: fib.c
	$(CC) $(CFLAGS) -c fib.c

clean:
	rm fib
	rm *.o
