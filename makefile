include makefile.include


all:


test-enhancer:
	$(MAKE) -$(MAKEFLAGS) -C enhancer test

build/doxygen/raisin.chm: Doxyfile
	mkdir -p build/doxygen
	doxygen -w html $<

build/doxygen/raisin.hu.chm: Doxyfile
	mkdir -p build/doxygen
	sed "s/^\(OUTPUT_LANGUAGE[[:blank:]]*= \).*/\1Hungarian/" $< | sed "s/raisin.chm/raisin.hu.chm/" | doxygen -
