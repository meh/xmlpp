h_sources = utils.h
cc_sources = utils.cpp

library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)-$(GENERIC_API_VERSION)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

noinst_LTLIBRARIES= libutils.la
libutils_la_SOURCES= $(h_sources) $(cc_sources)
