# Data Structures and Algorithms - Final Project

include Makefile.inc

.PHONY: all src lib clean

SRCS = \
	src/main/final_project.o \

INCS = \
	-I/include \

LIBS = \

all: src lib final_project run

final_project: $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

src:
	( cd src ; $(MAKE) all )

lib:
	( cd lib ; $(MAKE) all )

run:
	./final_project

clean:
	( cd src ; $(MAKE) clean )
	( cd lib ; $(MAKE) clean )
