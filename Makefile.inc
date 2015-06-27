# Data Structures and Algorithms - Final Project
# The main Makefile.inc
#
# Make sure $(DSA) is set to the root of this project

ACCOUNT = AVLTREE
# HISTORY = HASHMAP
HISTORY =

CC       = gcc
CXX      = g++
CFLAGS   = -O2 -std=c99 -Wall
CXXFLAGS = -O2 -std=c++11 -Wall

RM       = rm -rf
RANLIB   = ranlib
AR       = ar
ARFLAGS  = rv
ARCHIVE  = $(AR) $(ARFLAGS)

INCLUDE  = -I$(DSA)/src/core
LIBRARY  = $(DSA)/lib/libcore.a -lcrypto

ifeq ($(ACCOUNT), AVLTREE)
	INCLUDE += -I$(DSA)/src/account_avl_tree
	LIBRARY += $(DSA)/lib/libaccountavltree.a
else
	INCLUDE += -I$(DSA)/src/account_void
	LIBRARY +=
endif

ifeq ($(HISTORY), HASHMAP)
	INCLUDE += -I$(DSA)/src/history_hash_map
	LIBRARY += $(DSA)/lib/libhistoryhashmap.a
else
	INCLUDE += -I$(DSA)/src/history_void
	LIBRARY +=
endif
