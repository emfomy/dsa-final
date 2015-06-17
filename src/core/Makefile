# Data Structures and Algorithms - Final Project
# Makefile of /src/core

include ../../Makefile.inc

.PHONY: all clean

INCS = \
	-I../../include \

LIBS = \

TARGETS = \

OBJECTS = \
	final_project.o \
	bank.o \

HEADERS = \
	core.hpp \
	bank.hpp \
	account.hpp \
	../../include/account_set.hpp \

all: $(TARGETS) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

clean:
	$(RM) $(TARGETS) $(OBJECTS)
