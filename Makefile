# Data Structures and Algorithms - Final Project
# The main Makefile

include Makefile.inc

.PHONY: all src lib clean

TARGET = \
	final_project

SRCS = \
	src/core/final_project.o \
	src/core/bank.o \

INCS = \
	-I/include \

LIBS = \

all: src lib $(TARGET)

$(TARGET): $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

src:
	( cd src ; $(MAKE) all )

lib:
	( cd lib ; $(MAKE) all )

run: $(TARGET)
	./$(TARGET)

clean:
	( cd src ; $(MAKE) clean )
	( cd lib ; $(MAKE) clean )
