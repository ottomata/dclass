CFLAGS=
LDFLAGS=
SOVERSION = 2
lib_LTLIBRARIES = libdclassjni.la

libdclassjni_la_SOURCES = src/dtree_core.c     \
                          src/openddr_client.c \
                          src/dclass_file.c    \
                          src/dtree_mem.c      \
                          src/dtree_util.c     \
                          src/dclass_client.c  \
			  jni/dclass-wrapper.c


libdclassjni_la_CFLAGS  = -g -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -Wall -I ./jni/ -I./src/
libdclassjni_la_LDFLAGS = -D__X86_64__ -fPIC  -shared -DSHARED_OBJECT -Wl,--no-undefined

