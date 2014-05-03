#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([evmdd], [0.0.9], [radu@nianet.org])
AC_CONFIG_SRCDIR([src/mdd_manager.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

# Configure options
AC_ARG_ENABLE([debug],
              [AS_HELP_STRING([--enable-debug], [compile with -O0 -ggdb3 (default -O3)])],,
              [enable_debug=no])

AC_ARG_ENABLE([profiling],
              [AS_HELP_STRING([--enable-profiling], [compile with -pg])],
              [AS_IF([test "x$enableval" != xno -a "x$enable_debug" != xno],
                AC_MSG_WARN([conjunction of --enable-debug and --enable-profiling leading to profile not optimized programm]))],
              [enable_profiling=no])

CFLAGS="-ansi -pedantic -Wall ${CFLAGS}"
AS_IF([test "x$enable_debug" != xno],
      [CFLAGS="-O0 -ggdb3 ${CFLAGS}"],
      [CFLAGS="-DNDEBUG -O3 ${CFLAGS}"])
AS_IF([test "x$enable_profiling" != xno],
      [CFLAGS="-pg ${CFLAGS}"])

# Checks for programs.
AC_PROG_CC
LT_PREREQ([2.2.6])
LT_INIT([disable-shared])
AC_PROG_INSTALL

DX_HTML_FEATURE(ON)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN($PACKAGE_NAME, doxygen.cfg)

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([limits.h stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile src/Makefile evmdd.pc])
AC_OUTPUT

echo ""
echo "Configuration for $PACKAGE $VERSION :"
echo "-------------------------------"
echo ""
echo "  Compiled with debug information ......... : $enable_debug"
echo "  Compiled with profiling information ..... : $enable_profiling"
echo "  Resulting compiling flags ............... : ${CFLAGS}"
echo ""
echo "  Now type 'make' to build $PACKAGE $VERSION,"
echo "  and then type 'make install' for installation."
echo ""
