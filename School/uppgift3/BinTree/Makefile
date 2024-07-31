# Makefile for uppgift2
# Körs med module flaggan, "$ make module"

CC= gcc
CFLAGS= -g -c -MMD
LDFLAGS= -g
SOURCES= bintree.c
OBJECTS=$(SOURCES:.c=.o)

module: $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $<

-include $(SOURCES:.c=.d)

clean:
	rm -Rf *.o
	rm -Rf *.d

run:
	main
