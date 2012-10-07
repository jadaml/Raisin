include ../makefile.include

test: test-utf8

test-utf8: algo/utf8.o test/utf8.bin

algo/utf8.o: .force_look
	${SUBDIR_MAKE}

test/utf8.bin: .force_look
	${SUBDIR_MAKE}

