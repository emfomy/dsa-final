# Data Structures and Algorithms - Final Project
# Makefile of /src/core
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

.PHONY: all clean

INCS = \
	-I$(DSA)/include \

LIBS = \

OBJECTS = \
	final_project.o \
	bank.o \
	account.o \

HEADERS = \
	core.hpp \
	bank.hpp \
	account.hpp \
	$(DSA)/include/account_map.hpp \

all: $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

clean:
	$(RM) $(OBJECTS)
