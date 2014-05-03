## Source directory

inc_sources = evmdd.h \
              sal_intf.h \
              evmdd_node.h \
              mdd_manager.h \
              saturate_dist.h \
              saturate_dist2.h \
              saturate_bounded.h \
              events.h \
              evmdd_ops.h \
              mdd_node.h \
              bigint.h \
              mdd_ops.h \
              saturate.h

h_sources = $(inc_sources) \
            mdd_utils_priv.h \
            bigint_priv.h \
            evmdd_node_priv.h \
            events_priv.h \
            mdd_node_priv.h \
            mdd_manager_priv.h \
            garbage_collector_priv.h  \
            clock_priv.h \
            unique_table_priv.h

nodist_h_sources = cache_priv.h

c_sources = mdd_utils.c \
            bigint.c \
            evmdd_node.c \
            garbage_collector.c \
            mdd_manager.c \
            saturate.c \
            clock.c \
            unique_table.c \
            events.c \
            evmdd_ops.c \
            mdd_node.c \
            mdd_ops.c \
            saturate_dist.c \
            saturate_dist2.c \
            saturate_bounded.c \
            sal_intf.c

nodist_c_sources = cache.c

library_includedir=$(includedir)/evmdd
library_include_HEADERS = $(inc_sources)

INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES=libevmdd.la
libevmdd_la_SOURCES= $(h_sources) $(c_sources)
nodist_libevmdd_la_SOURCES= $(nodist_h_sources) $(nodist_c_sources)

## Cache compilation mechanism

BUILT_SOURCES=$(nodist_h_sources)

CLEANFILES = $(nodist_h_sources) $(nodist_c_sources) cache_generator
EXTRA_DIST = cache.desc cache_generator.c

cache.c cache_priv.h: cache.desc cache_generator
	./cache_generator $< cache_priv.h cache.c

cache_generator: cache_generator.c
	$(CC) -Wall -o $@ $<
