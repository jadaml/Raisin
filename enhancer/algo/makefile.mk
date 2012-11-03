include ..\..\include.mk

all: utf8.obj

utf8.obj: utf8.c utf8.h
	$(COMPILE.c) -o $@ $<

