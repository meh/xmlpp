h_sources = parser.h
cc_sources = parser.cpp

library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)-$(GENERIC_API_VERSION)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libxml.la
libxml_la_SOURCES= $(h_sources) $(cc_sources)
