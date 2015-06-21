# Data Structures and Algorithms - Final Project
# Makefile of /src/account_skip_list
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

.PHONY: all clean

TARGETDIR = $(DSA)/lib

TARGET = \
	$(TARGETDIR)/libaccountskiplist.a \

INCS = \
	-I$(DSA)/include \

LIBS = \

OBJECTS = \
	account_map.o \

HEADERS = \
	account_map.hpp \
	$(DSA)/include/dsa.hpp \
	$(DSA)/include/bank.hpp \
	$(DSA)/include/account.hpp \
	$(DSA)/include/history_map.hpp \

all: $(TARGET)
	@echo > /dev/null

$(TARGET): $(OBJECTS) $(TARGETDIR)
	$(ARCHIVE) $@ $(OBJECTS)
	-$(RANLIB) $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

clean:
	$(RM) $(TARGET) $(OBJECTS)
