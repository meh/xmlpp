SUBDIRS = DOM XML

h_sources = xml++.h common.h DOM.h XML.h Utils.h Parser.h
cc_sources = Utils.cpp Parser.cpp
library_includedir=/usr/include/xml++
library_include_HEADERS = $(h_sources)

INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES= libxmlpp.la
libxmlpp_la_SOURCES= $(h_sources) $(cc_sources)
libxmlpp_la_LIBADD= DOM/libdom.la XML/libxml.la
