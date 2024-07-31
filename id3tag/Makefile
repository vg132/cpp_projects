# Makefile for VG Software Window Framework

CCPLUS=g++
CPPFLAGS=-Wall -g -c
SOURCES= id3.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=main

all: main

main: $(OBJECTS)
	$(CCPLUS) $(OBJECTS) -o $(TARGET)

.c.o:
	$(CCPLUS) $(CPPFLAGS) $<

run:
	$(TARGET)

clean:
	rm -Rf $(OBJECTS)
	rm -Rf $(PROGNAME)
	rm -Rf $(ARTARGET)
	rm -Rf $(TARGET)
