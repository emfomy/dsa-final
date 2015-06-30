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

LIBS = \

OBJECTS = \
	skip_list_for_account.o \
	account_map.o \

HEADERS = \
	account_map.hpp \
	skip_list_for_account.hpp \

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
