include ../../makefile.include

utf8.bin: utf8.o ../algo/utf8.o
	${LINK.c} -o "../test/$@" $^

utf8.o: utf8.c ../algo/utf8.h
	${COMPILE.c} -o "../test/$@" $<

../algo/utf8.o: .force_look
	${SUBDIR_MAKE}

