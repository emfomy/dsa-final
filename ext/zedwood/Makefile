# zedwood: md5 function
# The main Makefile

export ZEDWOOD=$(CURDIR)

include $(ZEDWOOD)/Makefile.inc

SUBDIR = src

.PHONY: all $(SUBDIR) clean

all: $(SUBDIR)
	@echo > /dev/null

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
