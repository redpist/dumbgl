CC=gcc
CXX=g++
RM=rm -f
AR=ar -rs
INCFLAGS=-I include/
CPPFLAGS=$(shell tools/dumbgl-cflags) $(INCFLAGS)
LDFLAGS=$(shell tools/dumbgl-lib)

SRCS=src/dumbgl.cc src/dumbgl-c-bindings.cc
OBJS=$(subst .cc,.o,$(SRCS))

LIB=libdumbgl.a

INSTALL_DIR=/usr/local

all: $(LIB) tools

$(LIB): $(OBJS)
	$(AR) lib/$(LIB) $(OBJS)

tools: tools/dumbgl-config tools/dumbgl-cflags tools/dumbgl-lib
	cp -f tools/dumbgl-config bin/dumbgl-config
	cp -f tools/dumbgl-cflags bin/dumbgl-cflags
	cp -f tools/dumbgl-lib bin/dumbgl-lib

test: lib/$(LIB)
	$(CXX) test/0-c++-test.cc -L lib/ $(shell tools/dumbgl-config) $(INCFLAGS) -o test/build/0-c++-test
	$(CC) test/1-c-test.c -L lib/ $(shell tools/dumbgl-config) $(INCFLAGS) -o test/build/1-c-test

install: $(LIB) include/dumbgl.h tools test
	cp -f lib/$(LIB) $(INSTALL_DIR)/lib/$(LIB)
	cp -f include/dumbgl.h $(INSTALL_DIR)/include/dumbgl.h
	cp -f bin/dumbgl-config $(INSTALL_DIR)/bin/dumbgl-config

uninstall:
	rm -f $(INSTALL_DIR)/lib/$(LIB)
	rm -f $(INSTALL_DIR)/include/dumbgl.h
	rm -f $(INSTALL_DIR)/bin/dumbgl-config

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) $(wildcard test/build/*)

dist-clean: clean
	$(RM) *~ .depend

include .depend

.PHONY: test tools clean dist-clean install uninstall