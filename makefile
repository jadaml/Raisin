include makefile.include

all:

test-enhancer:
	${MAKE} -${MAKEFLAGS} -C enhancer test

