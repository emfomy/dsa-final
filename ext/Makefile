# Data Structures and Algorithms - Final Project
# Makefile of /ext
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

SUBDIR = gnu_avl openssl

.PHONY: all $(SUBDIR) clean

all: $(SUBDIR)
	@echo > /dev/null

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
