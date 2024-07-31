# Makefile for uppgift2
#
# För att kompilera modulen (binära trädet) kör, "make module"
# För att kompilera programmet (uppgift 2) kör, "make main"
# För att kompilera allt kör, "make all"

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
