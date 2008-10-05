h_sources = Document.h Attr.h Node.h Element.h Text.h DOMException.h
cc_sources = Document.cpp Attr.cpp Node.cpp Element.cpp Text.cpp DOMException.cpp

library_includedir=/usr/include/xml++/DOM
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libdom.la
libdom_la_SOURCES= $(h_sources) $(cc_sources)
