#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libdclass], [2.0.12], [dvanliere@wikimedia.org])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET

AM_INIT_AUTOMAKE

AM_PROG_LIBTOOL
LT_INIT
#AC_ENABLE_SHARED
#AC_DISABLE_STATIC
#AC_PROG_LIBTOOL(libtool)

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lrt':
AC_CHECK_LIB([rt], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([clock_gettime memset strcasecmp strncasecmp strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
