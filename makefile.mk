include include.mk

all:

test-enhancer:
	cd enhancer & $(MAKE) -$(MAKEFLAGS) /F makefile.mk test

build\doxygen\html\raisin.chm: Doxyfile
	mkdir build\doxygen
	doxygen -w html $<

