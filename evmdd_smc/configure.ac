#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([evmdd-smc], [0.0.9], [radu@nianet.org])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADER([config.h])
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
CFLAGS=${CFLAGS}
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_YACC
AM_PROG_LEX

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
AC_CHECK_LIB(fl, yywrap)

AC_ARG_WITH(evmdd, [AS_HELP_STRING([--with-evmdd=/path/to/evmdd/lib/include],[Directory where evmdd is installed])])

AS_IF([test -z "$with_evmdd"],
#        [PKG_CHECK_MODULES(LIBEVMDD, evmdd)],
        [LIBEVMDD_CFLAGS="-I$with_evmdd/include"; LIBEVMDD_LIBS="-L$with_evmdd/lib -levmdd"])

AC_SUBST(LIBEVMDD_CFLAGS)
AC_SUBST(LIBEVMDD_LIBS)

AC_ARG_WITH([cudd],
            [AS_HELP_STRING([--with-cudd=<path>], [define <path> of cudd compiled library and headers relative to src directory (default ../..)])],,
            [with_cudd=../..])
AS_IF([test -d src/${with_cudd}],
        [AS_IF([test -d src/${with_cudd}/`ls src/${with_cudd} | grep cudd | head -1`],
          [with_cudd=${with_cudd}/`ls src/${with_cudd} | grep cudd | head -1`])],
        [with_cudd=no])
AS_IF([test ! -f "src/${with_cudd}/cudd/cudd.h"],
        [with_cudd=no])
AS_IF([test "x$with_cudd" == xno],
        [AC_MSG_WARN([CUDD library not found in given path (or no path given, see --with-cudd=<path/relative/to/src>) disabling CUDD support])],
        [AS_IF([test ! -f "src/${with_cudd}/cudd/libcudd.a" -o ! -d "src/${with_cudd}/include"],
          [AC_MSG_WARN([CUDD library found but not compiled disabling CUDD support])
           with_cudd=no])])
AS_IF([test "x$with_cudd" != xno],
        [AC_DEFINE([HAVE_CUDD], [1], [Compiled with CUDD support.])])
AS_IF([test "x$with_cudd" != xno],
        [LIBCUDD_CFLAGS="-I${with_cudd}/include"],
        [LIBCUDD_CFLAGS=""])
AS_IF([test "x$with_cudd" != xno],
        [LIBCUDD_LIBS="-L${with_cudd}/dddmp -ldddmp -L${with_cudd}/cudd -lcudd -L${with_cudd}/mtr -lmtr -L${with_cudd}/st -lst -L${with_cudd}/util -lcuddutil -L${with_cudd}/epd -lepd -lm"],
        [LIBCUDD_LIBS=""])
AC_SUBST(LIBCUDD_CFLAGS)
AC_SUBST(LIBCUDD_LIBS)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([limits.h stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strtoul])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

echo ""
echo "Configuration for $PACKAGE $VERSION :"
echo "-----------------------------------"
echo ""
echo "  Compiled with debug information ......... : $enable_debug"
echo "  Compiled with profiling information ..... : $enable_profiling"
echo "  Resulting compiling flags ............... : ${CFLAGS}"
echo "  Evmdd library ........................... : $LIBEVMDD_CFLAGS $LIBEVMDD_LIBS"
echo "  Compiled with CUDD ...................... : $with_cudd"
echo "  CUDD library ............................ : $LIBCUDD_CFLAGS $LIBCUDD_LIBS"
echo ""
echo "  Now type 'make' to build $PACKAGE $VERSION."
echo ""
