# Makefile for VG Software Window Framework

CCPLUS=g++
CPPFLAGS=-Wall -g -c -I./include
AR=ar
ARFLAGS=rcs
ARTARGET=lib/libvwf.a
SOURCES=src/size.cpp src/point.cpp src/actionbase.cpp src/rect.cpp src/screenobject.cpp src/objectdata.cpp src/active.cpp src/passive.cpp src/edit.cpp src/menu.cpp src/button.cpp src/label.cpp src/frame.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: lib

lib: $(OBJECTS)
	$(AR) $(ARFLAGS) $(ARTARGET) $(OBJECTS)

.c.o:
	$(CCPLUS) $(CPPFLAGS) $<

clean:
	rm -Rf $(OBJECTS)
	rm -Rf $(ARTARGET)

