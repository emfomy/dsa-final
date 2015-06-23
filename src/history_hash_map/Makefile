# Data Structures and Algorithms - Final Project
# Makefile of /src/history_hash_map
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

.PHONY: all clean

TARGETDIR = $(DSA)/lib

TARGET = \
	$(TARGETDIR)/libhistoryhashmap.a \

INCS = \
	-I$(DSA)/include \

LIBS = \

OBJECTS = \
	history.o \
	history_map.o \
	history_node.o \

HEADERS = \
	history.hpp \
	history_map.hpp \
	history_node.hpp \
	$(DSA)/include/dsa.hpp \
	$(DSA)/include/bank.hpp \
	$(DSA)/include/account.hpp \
	$(DSA)/include/account_map.hpp \

all: $(TARGET)
	@echo > /dev/null

$(TARGET): $(OBJECTS) | $(TARGETDIR)
	$(ARCHIVE) $@ $(OBJECTS)
	-$(RANLIB) $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

clean:
	$(RM) $(TARGET) $(OBJECTS)
