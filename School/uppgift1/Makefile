# Makefile for uppgift1

CC= gcc
CFLAGS= -g -c -MMD
LDFLAGS= -g
SOURCES= test.c
#list.c upp1.c
OBJECTS=$(SOURCES:.c=.o)

main: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $<

-include $(SOURCES:.c=.d)

clean:
	rm -Rf *.o
	rm -Rf *.d
