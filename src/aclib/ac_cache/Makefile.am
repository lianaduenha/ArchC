## Process this file with automake to produce Makefile.in

## Includes
AM_CPPFLAGS = -I. -I$(top_srcdir)/src/aclib/ac_decoder -I$(top_srcdir)/src/aclib/ac_gdb -I$(top_srcdir)/src/aclib/ac_core -I$(top_srcdir)/src/aclib/ac_syscall -I$(top_srcdir)/src/aclib/ac_utils @SYSTEMC_CFLAGS@

## The ArchC library
noinst_LTLIBRARIES = libaccache.la

## ArchC library includes
include_HEADERS = ac_cache_bhv.H ac_cache.H ac_cache_if.H ac_cache_replacement_policy.H ac_cache_trace.H ac_fifo_replacement_policy.H ac_lru_replacement_policy.H ac_plrum_replacement_policy.H ac_random_replacement_policy.H ac_cache_power.H cacheMem.h cacheBlock.h ac_dirport.H

libaccache_la_SOURCES = ac_cache_trace.cpp cacheBlock.cpp cacheMem.cpp  

install-data-hook:
	mkdir -p $(pkgdatadir)/powersc; \
	for file in powersc/*; do \
		cp -f $(srcdir)/$${file} $(pkgdatadir)/$${file}; \
	done;




