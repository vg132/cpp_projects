# Makefile for uppgift2
#
# F�r att kompilera modulen (bin�ra tr�det) k�r, "make module"
# F�r att kompilera programmet (uppgift 2) k�r, "make main"
# F�r att kompilera allt k�r, "make all"

CC= gcc
CFLAGS= -g -c 
LDFLAGS= -g
SOURCES= textindex.c
OBJECTS=$(SOURCES:.c=.o)
MODSOURCES= bintree.c
MODOBJECTS=$(MODSOURCES:.c=.o)

all: module main

main: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MODOBJECTS) -o $@

module: $(MODOBJECTS)

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -Rf *.o
