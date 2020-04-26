# Makefile for 'set' module
#
# Eyasu Lemma, Spring 2020


CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common
CC = gcc

#rules
settest: set.o ../common/memory.o settest.c 
		$(CC) $(CFLAGS) $^ -o $@


.PHONY: test clean

test: 
	./settest < test_set

clean:
	rm -f *~ *.o *.dSYM
	rm -f settest
	rm -f stocks

