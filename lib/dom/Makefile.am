h_sources = dom.h document.h child.h attribute.h element.h text.h 
cc_sources = dom.cpp document.cpp child.cpp attribute.cpp element.cpp text.cpp

library_includedir=/usr/include/xml++/dom
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libdom.la
libdom_la_SOURCES= $(h_sources) $(cc_sources)
