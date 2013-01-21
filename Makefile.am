CFLAGS=
SOVERSION = 2
lib_LTLIBRARIES = libdclass.la libdclassjni.la

libdclass_la_SOURCES = src/dtree_core.c     \
		       src/openddr_client.c \
		       src/dclass_file.c    \
                       src/dtree_mem.c      \
                       src/dtree_util.c     \
                       src/dclass_client.c

libdclassjni_la_SOURCES = jni/dclass-wrapper.c
libdclassjni_la_CFLAGS  = -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -Wall -I ./jni/ -I./src/
libdclassjni_la_LDFLAGS = -version-info $(SOVERSION) -no-undefined

libdclass_la_CFLAGS = -g
libdclass_la_LDFLAGS = -shared
