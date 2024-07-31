# Makefile for VG Software Window Framework

CCPLUS=g++
CPPFLAGS=-Wall -g -c -I../framework/include
LDFLAGS= -g -L../framework/lib
SOURCES= src/app.cpp src/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=bin/test
LIBS= -lvwf -lterm

all: main

main: $(OBJECTS)
	$(CCPLUS) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(TARGET)

.c.o:
	$(CCPLUS) $(CPPFLAGS) $<

run:
	$(TARGET)

clean:
	rm -Rf $(OBJECTS)
	rm -Rf $(PROGNAME)
	rm -Rf $(ARTARGET)
	rm -Rf $(TARGET)
