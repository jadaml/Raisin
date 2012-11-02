include ../../makefile.include

paths-macro.o: paths.cc paths.h
	$(COMPILE.cc) -DDATADIR='"/usr/local/share"' -DPACKAGE_NAME='"Enhancer Test"' -DPACKAGE_TARNAME='"enhancer"' $< -o $@

