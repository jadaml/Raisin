include include.mk

all:

test-enhancer:
	cd enhancer & $(MAKE) -$(MAKEFLAGS) /F makefile.mk test

