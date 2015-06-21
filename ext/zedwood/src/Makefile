# zedwood: md5 function
# Makefile of /src
#
# Make sure $(ZEDWOOD) is set to the root of this project

include $(ZEDWOOD)/Makefile.inc

.PHONY: all clean

TARGETDIR = $(ZEDWOOD)/lib

TARGET = \
	$(TARGETDIR)/libmd5.a \

INCS = \
	-I$(ZEDWOOD)/include

LIBS = \

OBJECTS = \
	md5.o \

HEADERS = \

all: $(TARGET)
	@echo > /dev/null

$(TARGET): $(OBJECTS) $(TARGETDIR)
	$(ARCHIVE) $@ $(OBJECTS)
	-$(RANLIB) $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

clean:
	$(RM) $(TARGET) $(OBJECTS)
