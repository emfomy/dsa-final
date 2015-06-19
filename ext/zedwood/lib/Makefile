# zedwood: md5 function
# Makefile of /lib
#
# Make sure $(ZEDWOOD) is set to the root of this project

include $(ZEDWOOD)/Makefile.inc

.PHONY: all clean

TARGET = \
	libmd5.a \

OBJECTS = \
	$(ZEDWOOD)/src/md5.o \

all: $(TARGET)

libmd5.a: $(OBJECTS)
	$(ARCHIVE) $@ $(OBJECTS)
	- $(RANLIB) $@

clean:
	$(RM) $(TARGET)
