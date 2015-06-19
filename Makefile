# Data Structures and Algorithms - Final Project
# The main Makefile

export DSA=$(CURDIR)

include $(DSA)/Makefile.inc

.PHONY: all ext src lib clean

TARGET = \
	final_project

SRCS = \
	src/core/final_project.o \
	src/core/bank.o \

INCS = \
	-I$(DSA)/include \

LIBS = \

all: ext src lib $(TARGET)

$(TARGET): $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

ext:
	( cd ext ; $(MAKE) all )

src:
	( cd src ; $(MAKE) all )

lib:
	( cd lib ; $(MAKE) all )

run: $(TARGET)
	./$(TARGET)

clean:
	( cd ext ; $(MAKE) clean )
	( cd src ; $(MAKE) clean )
	( cd lib ; $(MAKE) clean )
