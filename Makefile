# Data Structures and Algorithms - Final Project
# The main Makefile

export DSA=$(CURDIR)

include $(DSA)/Makefile.inc

.PHONY: all src lib ext clean

MAKEFLAGS += --no-print-directory

TARGET = \
	final_project \

SRCS = \
	src/main/final_project.cpp \

INCS = \
	-I$(DSA)/include \

LIBS = \
	$(DSA)/lib/libcore.a \

all: src lib ext main
	@echo > /dev/null

$(TARGET): $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCS) $(INCLUDE) $(LIBS) $(LIBRARY) -o $@

src:
	@( cd src ; $(MAKE) all )

lib:
	@( cd lib ; $(MAKE) all )

ext:
	@( cd ext ; $(MAKE) all )

main: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	@( cd src ; $(MAKE) clean )
	@( cd lib ; $(MAKE) clean )
	@( cd ext ; $(MAKE) clean )
