# Makefile for uppgift2

CC= gcc
CFLAGS= -g -c -MMD
LDFLAGS= -g
SOURCES= textindex.c
OBJECTS=$(SOURCES:.c=.o)

main: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) bintree.o -o $@

.c.o:
	$(CC) $(CFLAGS) $<

-include $(SOURCES:.c=.d)

clean:
	rm -Rf *.o
	rm -Rf *.d
