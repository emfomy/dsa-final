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
	bank.o \
	account.o \

HEADERS = \
	$(DSA)/include/dsa.hpp \
	bank.hpp \
	$(DSA)/include/account_map.hpp \
	account.hpp \
	$(DSA)/include/history_map.hpp \

all: $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

clean:
	$(RM) $(OBJECTS)
