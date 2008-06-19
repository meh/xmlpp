h_sources = exception.h xml_exception.h dom_exception.h
cc_sources = exception.cpp xml_exception.cpp dom_exception.cpp

library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)-$(GENERIC_API_VERSION)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libexception.la
libexception_la_SOURCES= $(h_sources) $(cc_sources)
