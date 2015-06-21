# zedwood: md5 function
# Makefile of /src
#
# Make sure $(ZEDWOOD) is set to the root of this project

include $(ZEDWOOD)/Makefile.inc

.PHONY: all clean

INCS = \
	-I$(ZEDWOOD)/include

LIBS = \

OBJECTS = \
	md5.o \

HEADERS = \

all: $(OBJECTS)
	@echo > /dev/null

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCS) $(INCLUDE) -o $@

clean:
	$(RM) $(OBJECTS)
