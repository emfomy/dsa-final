# Data Structures and Algorithms - Final Project
# The main Makefile.inc
#
# Make sure $(DSA) is set to the root of this project

ACCOUNT ?= HASHMAP
HISTORY ?= HASHMAP

CC       = gcc
CXX      = g++
CFLAGS   = -O2 -std=c99 -Wall
CXXFLAGS = -O2 -std=c++11 -Wall

RM       = rm -rf
RANLIB   = ranlib
AR       = ar
ARFLAGS  = rv
ARCHIVE  = $(AR) $(ARFLAGS)

SRCDIR = core
INCLUDE  = -I$(DSA)/src/core -I$(DSA)/ext/openssl/include
LIBRARY  = $(DSA)/lib/libcore.a $(DSA)/ext/openssl/lib/libcrypto.a

ifeq ($(ACCOUNT), AVLTREE)
	SRCDIR += account_avl_tree
	INCLUDE += -I$(DSA)/src/account_avl_tree -I$(DSA)/ext/gnu_avl/src
	LIBRARY += $(DSA)/lib/libaccountavltree.a $(DSA)/ext/gnu_avl/lib/libavl.a
else ifeq ($(ACCOUNT), HASHMAP)
	SRCDIR += account_hash_map
	INCLUDE += -I$(DSA)/src/account_hash_map
	LIBRARY += $(DSA)/lib/libaccounthashmap.a
else ifeq ($(ACCOUNT), SKIPLIST)
	SRCDIR += account_skip_list
	INCLUDE += -I$(DSA)/src/account_skip_list
	LIBRARY += $(DSA)/lib/libaccountskiplist.a
else
	INCLUDE += -I$(DSA)/src/account_void
	LIBRARY +=
endif

ifeq ($(HISTORY), HASHMAP)
	SRCDIR += history_hash_map
	INCLUDE += -I$(DSA)/src/history_hash_map
	LIBRARY += $(DSA)/lib/libhistoryhashmap.a
else
	INCLUDE += -I$(DSA)/src/history_void
	LIBRARY +=
endif
