#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([dclass-jni], [0.1], [dvanliere@wikimedia.org])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([dclass-wrapper.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4]]

LT_INIT
AC_ENABLE_SHARED

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h jni.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
