BUILT_SOURCES = parser.h
AM_YFLAGS = -d
AM_CPPFLAGS = $(LIBEVMDD_CFLAGS) $(LIBCUDD_CFLAGS)

bin_PROGRAMS = evmdd-smc

evmdd_smc_SOURCES = utils.h \
                    utils.c \
                    ast.h \
                    ast.c \
                    env.h \
                    env.c \
                    normalize.h \
                    normalize.c \
                    parser.y \
                    scanner.l \
                    bfs.h \
                    bfs.c \
                    clock.h \
                    clock.c \
                    build.h \
                    build.c \
                    ctl.h \
                    ctl.c \
                    implicit_identities.h \
                    implicit_identities.c \
                    cuthill_mckee.h \
                    cuthill_mckee.c \
                    precompiled_ast_cudd.h \
                    precompiled_ast_cudd.c \
                    build_cudd.h \
                    build_cudd.c \
                    event_cudd.h \
                    event_cudd.c \
                    trans_cudd.h \
                    trans_cudd.c \
                    bfs_cudd.h \
                    bfs_cudd.c \
                    ctl_cudd.h \
                    ctl_cudd.c \
                    ef_trace_cudd.h \
                    ef_trace_cudd.c \
                    test_cudd.h \
                    test_cudd.c \
                    ef_trace.h \
                    ef_trace.c \
                    main.c

evmdd_smc_LDADD = $(LIBEVMDD_LIBS) $(LIBCUDD_LIBS)
