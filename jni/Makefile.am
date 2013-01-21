#NAME=dclass-jni
#VERSION=0.0.1
#SOURCES=dclass-wrapper.c
#HEADERS=dclass-wrapper.h
#DCLASS_PATH=../src
#EXTA_DIST=AUTHORS COPYING Makefile
ACLOCAL_AMFLAGS = -I m4
#DCLASS= $DCLASS_PATH/dtree_core.o        \
#        $DCLASS_PATH/openddr_client.o    \
#        $DCLASS_PATH/dclass_file.o       \
#        $DCLASS_PATH/dtree_mem.o         \
#        $DCLASS_PATH/dtree_util.o        \
#        $DCLASS_PATH/dclass_client.o     \
lib_LTLIBRARIES = libdclassjni.la
libdclassjni_la_SOURCES = dclass-wrapper.c
libdclassjni_la_HEADERS = dclass-wrapper.h
libdclassjni_la_LIBADD = jni.h
libdclassjni_la_CFLAGS = -Wall
libdclassjni_la_LDFLAGS = -version-info $(VERSION) -no-undefined
#libdir = /home/diederik/libs/
#pkgconfigdir = $(libdir)/pkgconfig
#pkgconfig_DATA = libdclassjni-1.pc
