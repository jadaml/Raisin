include ../../makefile.include

all: system.run macros.run utf8.bin

macros.run: macros.o ../system/paths-macro.o ../system/osdetect.o
	$(LINK.cc) $^ -o $@

macros.o: macros.c ../system/paths.h ../system/osdetect.h
	$(COMPILE.c) -DDATADIR="/usr/local/share" -DPACKAGE_NAME="Enhancer Test" $< -o $@

system.run: system.o ../system/paths.o ../system/osdetect.o
	$(LINK.cc) $^ -o $@

system.o: system.c ../system/paths.h ../system/osdetect.h
	$(COMPILE.c) $< -o $@

utf8.bin: utf8.o ../algo/utf8.o
	${LINK.c} -o "../test/$@" $^

utf8.o: utf8.c ../algo/utf8.h
	${COMPILE.c} -o "../test/$@" $<

../algo/utf8.o: .force_look
	${SUBDIR_MAKE}

