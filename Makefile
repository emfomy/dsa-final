# Data Structures and Algorithms - Final Project
# The main Makefile

export DSA=$(CURDIR)

include $(DSA)/Makefile.inc

MAKEFLAGS += --no-print-directory

SUBDIR = src ext

.PHONY: all $(SUBDIR) clean

TARGET = \
	final_project \

SRCS = \
	src/main/final_project.cpp \

INCS = \
	-I$(DSA)/include \

LIBS = \
	$(DSA)/lib/libcore.a \
	$(DSA)/lib/libaccounthashmap.a \
	$(DSA)/lib/libhistoryhashmap.a \

all: $(SUBDIR) main
	@echo > /dev/null

$(TARGET): $(SRCS) $(LIBS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCS) $(INCLUDE) $(LIBS) $(LIBRARY) -o $@

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

main: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
