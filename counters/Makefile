# Makefile for 'counter' module
#
# Eyasu Lemma, Spring 2020


CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common
CC = gcc

#rules 
counterstest: counters.o ../common/memory.o counterstest.c
			$(CC) $(CFLAGS) $^ -o $@


.PHONY: test clean

test: 
	./counterstest < test_keys

clean:
	rm -f *~ *.o *.dSYM
	rm -f $ counterstest
	rm -f stocks
