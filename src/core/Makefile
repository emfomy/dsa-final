# Data Structures and Algorithms - Final Project
# Makefile of /src/core
#
# Make sure $(DSA) is set as the root of this project

include $(DSA)/Makefile.inc

.PHONY: all clean

INCS = \
	-I$(DSA)/include \

LIBS = \

TARGETS = \

OBJECTS = \
	final_project.o \
	bank.o \

HEADERS = \
	core.hpp \
	bank.hpp \
	account.hpp \
	$(DSA)/include/account_map.hpp \

all: $(TARGETS) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

clean:
	$(RM) $(TARGETS) $(OBJECTS)
