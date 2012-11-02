include ../makefile.include

test: test-system test-macros test-utf8

test-system: test/system.run
	test/system.run

test-macros: test/macros.run
	test/macros.run

test/macros.run: .force_look system/paths-macro.o system/osdetect.o
	$(SUBDIR_MAKE)

test/system.run: .force_look system/paths.o system/osdetect.o
	$(SUBDIR_MAKE)

system/paths.o: .force_look
	$(SUBDIR_MAKE)

system/paths-macro.o: .force_look
	$(SUBDIR_MAKE)

system/osdetect.o: .force_look
	$(SUBDIR_MAKE)

test-utf8: algo/utf8.o test/utf8.bin

algo/utf8.o: .force_look
	${SUBDIR_MAKE}

test/utf8.bin: .force_look
	${SUBDIR_MAKE}

