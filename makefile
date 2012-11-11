include makefile.include

all:

test-enhancer:
	$(MAKE) -$(MAKEFLAGS) -C enhancer test

docset: Doxyfile
	rm -rfv build/doxygen/*.docset
	# sed seems to be broken
	doxygen Doxyfile
	$(MAKE) -C build/doxygen/html docset
	cp -rfv build/doxygen/html/*.docset build/doxygen

# Technically this shouldn't work, since Doxyfile CHM creation is configured for Windows only.
chm-doc: Doxyfile
	sed 's/\(^GENERATE_\(MAN\|LATEX\|RTF\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_HTMLHELP[[:blank:]]= \).*$/\1YES/' | doxygen -
	cp build/doxygen/html/raisin.chm build/

hu-chm-doc: Doxyfile
	sed 's/\(^GENERATE_\(MAN\|LATEX\|RTF\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_HTMLHELP[[:blank:]]= \).*$/\1YES/' | sed 's/\(^OUTPUT_LANGUAGE[[:blank:]]*= \).*$/\1Hungarian/' | sed 's/\(^CHM_FILE[[:blank:]]*= \).*$/\1raisin-hu.chm/' | doxygen -
	cp build/doxygen/html/raisin-hu.chm build/

html-doc: Doxyfile
	sed 's/\(^GENERATE_\(HTMLHELP\|MAN\|LATEX\|RTF\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | doxygen -

man_doc: Doxyfile
	sed 's/\(^GENERATE_\(HTML\|HTMLHELP\|LATEX\|RTF\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_MAN[[:blank:]]= \).*$/\1YES/' | doxygen -

rtf_doc: Doxyfile
	sed 's/\(^GENERATE_\(HTML\|HTMLHELP\|LATEX\|MAN\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_RTF[[:blank:]]= \).*$/\1YES/' | doxygen -

latex_doc: Doxyfile
	sed 's/\(^GENERATE_\(HTML\|HTMLHELP\|RTF\|MAN\|DOCSET\|ECLIPSEHELP\|QHP\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_LATEX[[:blank:]]= \).*$/\1YES/' | doxygen -

qt_doc: Doxyfile
	sed 's/\(^GENERATE_\(HTMLHELP\|RTF\|MAN\|DOCSET\|ECLIPSEHELP\|LATEX\)[[:blank:]]= \).*$/\1NO/' Doxyfile | sed 's/\(^GENERATE_QHP[[:blank:]]= \).*$/\1YES/' | doxygen -

.phony: chm-doc html-doc

