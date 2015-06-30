# Data Structures and Algorithms - Final Project
# GNU libavl
# The Makefile.inc of libavl
#
# Make sure $(GNUAVL) is set to the root of this project

CC       = gcc
CXX      = g++
CFLAGS   = -O2 -std=c99 -Wall
CXXFLAGS = -O2 -std=c++11 -Wall

RM       = rm -rf
RANLIB   = ranlib
AR       = ar
ARFLAGS  = rv
ARCHIVE  = $(AR) $(ARFLAGS)
