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

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) $(INCS) $(LIBRARY) $(LIBS) -o $@

clean:
	$(RM) $(OBJECTS)
