# Data Structures and Algorithms - Final Project
# GNU libavl
# Makefile of /ext/gnu_avl/src
#
# Make sure $(GNUAVL) is set to the root of this project

include $(GNUAVL)/Makefile.inc

.PHONY: all clean

TARGETDIR = $(GNUAVL)/lib

TARGET = \
	$(TARGETDIR)/libavl.a \

INCS = \

LIBS = \

OBJECTS = \
	avl.o \

HEADERS = \
	avl.h \

all: $(TARGET)
	@echo > /dev/null

$(TARGET): $(OBJECTS) | $(TARGETDIR)
	$(ARCHIVE) $@ $(OBJECTS)
	-$(RANLIB) $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

clean:
	$(RM) $(TARGET) $(OBJECTS)
