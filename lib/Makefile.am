SUBDIRS = dom xml exception utils

h_sources = xml++.h common.h dom.h
library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)-$(GENERIC_API_VERSION)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES= libxmlpp-0.1.la
libxmlpp_0_1_la_SOURCE= $(h_sources)
libxmlpp_0_1_la_LIBADD= dom/libdom.la xml/libxml.la exception/libexception.la utils/libutils.la
libxmlpp_0_1_la_LDFLAGS= -version-info $(GENERIC_LIBRARY_VERSION) -release $(GENERIC_RELEASE)
