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
	bank.hpp \
	account.hpp \
	$(DSA)/include/dsa.hpp \
	$(DSA)/include/account_map.hpp \
	$(DSA)/include/history_map.hpp \

all: $(OBJECTS)
	@echo > /dev/null

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

clean:
	$(RM) $(OBJECTS)
