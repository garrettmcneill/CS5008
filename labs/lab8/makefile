####################
# Makefile for Lecture 10 
# July 21, 2021
####################

CC=gcc
CFLAGS= -lpthread

#
# t1 makefile commands
#
t1: thread1.o
	$(CC) $(CFLAGS) -o t1 thread1.o

thread1.o: thread1.c
	$(CC) $(CFLAGS) -c thread1.c

#
# t2 makefile commands
#
t2: thread2.o
	$(CC) $(CFLAGS) -o t2 thread2.o

thread2.o: thread2.c
	$(CC) $(CFLAGS) -c thread2.c

#
# t3 makefile commands
#
t3: thread3.o
	$(CC) $(CFLAGS) -o t3 thread3.o

thread3.o: thread3.c
	$(CC) $(CFLAGS) -c thread3.c

#
# t4 makefile commands
#
t4: thread4.o
	$(CC) $(CFLAGS) -o t4 thread4.o

thread4.o: thread4.c
	$(CC) $(CFLAGS) -c thread4.c


clean:
	rm *.o
	rm t1 
	rm t2 
	rm t3 
	rm t4 
