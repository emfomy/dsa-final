# Data Structures and Algorithms - Final Project
# Makefile of /lib
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

.PHONY: all clean

TARGET = \
	libcore.a \

COREOBJECTS = \
	$(DSA)/src/core/bank.o \
	$(DSA)/src/core/account.o \

all: $(TARGET)
	@echo > /dev/null

libcore.a: $(COREOBJECTS)
	$(ARCHIVE) $@ $(COREOBJECTS)
	-$(RANLIB) $@

clean:
	$(RM) $(TARGET)
