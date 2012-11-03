include ../include.mk

test: test-utf8 test-macros test-system

test-utf8: algo\utf8.obj test\utf8.exe
	test\utf8.exe

test-system: test\system.exe
	test\system.exe

test-macros: test\macros.exe
	test\macros.exe

algo\utf8.obj: .focre_look
	$(MAKE) -$(MAKEFLAGS) -C algo utf8.obj

system\paths.obj: .force_look
	$(MAKE) -$(MAKEFLAGS) -C system paths.obj

system\paths-macro.obj: .force_look
	$(MAKE) -$(MAKEFLAGS) -C system paths-macro.obj

system\osdetect.obj: .force_look
	$(MAKE) -$(MAKEFLAGS) -C system osdetect.obj

test\utf8.exe: .focre_look
	$(MAKE) -$(MAKEFLAGS) -C test utf8.exe

test\system.exe: system\paths.obj system\osdetect.obj
	$(MAKE) -$(MAKEFLAGS) -C test system.exe

test\macros.exe: system\paths-macro.obj system\osdetect.obj
	$(MAKE) -$(MAKEFLAGS) -C test macros.exe

