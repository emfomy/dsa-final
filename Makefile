# Data Structures and Algorithms - Final Project
# The main Makefile

export DSA=$(CURDIR)

include $(DSA)/Makefile.inc

.PHONY: all ext src lib clean

TARGET = \
	final_project \

SRCS = \
	src/main/final_project.cpp \

INCS = \
	-I$(DSA)/include \

LIBS = \
	$(DSA)/lib/libcore.a \

all: ext src lib main

$(TARGET): $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCS) $(INCLUDE) $(LIBS) $(LIBRARY) -o $@

ext:
	( cd ext ; $(MAKE) all )

src:
	( cd src ; $(MAKE) all )

lib:
	( cd lib ; $(MAKE) all )

main: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	( cd ext ; $(MAKE) clean )
	( cd src ; $(MAKE) clean )
	( cd lib ; $(MAKE) clean )
