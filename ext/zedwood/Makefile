# zedwood: md5 function
# The main Makefile

export ZEDWOOD=$(CURDIR)

include $(ZEDWOOD)/Makefile.inc

.PHONY: all src lib clean

all: src lib
	@echo > /dev/null

src:
	@( cd src ; $(MAKE) all )

lib:
	@( cd lib ; $(MAKE) all )

clean:
	@( cd src ; $(MAKE) clean )
	@( cd lib ; $(MAKE) clean )
