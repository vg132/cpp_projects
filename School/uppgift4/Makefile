# Makefile for uppgift3

CC= gcc
CFLAGS= -g -c 
LDFLAGS= -g
MODSOURCES= cset.c
MODOBJECTS=$(MODSOURCES:.c=.o)

all: module

module: $(MODOBJECTS)

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -Rf *.o
