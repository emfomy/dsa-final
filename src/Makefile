# Data Structures and Algorithms - Final Project
# Makefile of /src
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

SUBDIR = core

.PHONY: all $(SUBDIR) clean

all: $(SUBDIR)
	@echo > /dev/null

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
