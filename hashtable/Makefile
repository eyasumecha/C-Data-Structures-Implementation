# Makefile for 'hashtable' module
#
# Eyasu Lemma, Spring 2020

PROG = hashtest
OBJS = hashtest.o hashtable.o ../common/memory.o ../set/set.o jhash.o
LIBS =


CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common 
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@
hashtest.o: hashtable.h 
hashtable.o: hashtable.h ../set/set.h
jhash.o: jhash.h
memory.o: ../memory/memory.h

.PHONY: test clean

test: $(PROG) test_hash
	./$(PROG) < test_hash
	

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f stocks
