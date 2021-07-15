####################
# Makefile for Lab 7 Recitation
# July 15, 2021
####################

CC=gcc
CFLAGS= -Wall

#
# mem makefile commands
#
mem: mem1.o
	$(CC) $(CFLAGS) -o mem mem1.o

mem1.o: mem1.c
	$(CC) $(CFLAGS) -c mem1.c

#
# str makefile commands
#
str: str1.o
	$(CC) $(CFLAGS) -o str str1.o

str1.o: str1.c
	$(CC) $(CFLAGS) -c str1.c

#
# sort makefile commands
#
sort: sort.o
	$(CC) $(CFLAGS) -o sort sort.o

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

#
# resize makefile commands
#
resize: resize.o
	$(CC) $(CFLAGS) -o resize resize.o

resize.o: resize.c
	$(CC) $(CFLAGS) -c resize.c

clean:
	rm *.o
	rm mem 
	rm str
	rm resize
	rm sort
