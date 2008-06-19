h_sources = document.h child.h attribute.h element.h text.h
cc_sources = document.cpp child.cpp attribute.cpp element.cpp text.cpp

library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)-$(GENERIC_API_VERSION)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libdom.la
libdom_la_SOURCES= $(h_sources) $(cc_sources)
