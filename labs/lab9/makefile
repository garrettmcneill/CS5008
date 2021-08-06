####################
# Makefile for Lab 9 Recitation
# July 29, 2021
####################

CC=gcc
CFLAGS= -Wall

#
# tries makefile commands
#
trie: trie1.o
	$(CC) $(CFLAGS) -o trie trie1.o

trie1.o: trie1.c
	$(CC) $(CFLAGS) -c trie1.c

clean:
	rm *.o
	rm trie
