# Makefile for 'hashtable' module
#
# David Kotz, April 2016, 2017, 2019, 2021
# updated by Xia Zhou, July 2016, 2018, January 2019
# Used by Alina Chadwick, CS10 Lab 3

OBJS = hashtabletest.o hashtable.o ../set/set.o hash.o ../lib/file.o ../lib/mem.o 
LIBS = -lm

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

hashtabletest: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h ../lib/file.h
hashtable.o: hashtable.h hash.h ../set/set.h
set.o: ../set/set.h
# ../lib/file.o: ../lib/file.h

.PHONY: test valgrind clean

# expects a file `test.names` to exist; it can contain any text.
test: hashtabletest test.names
	./hashtabletest < test.names

# expects a file `test.names` to exist; it can contain any text.
valgrind: hashtabletest test.names
	valgrind ./hashtabletest < test.names

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f bagtest

