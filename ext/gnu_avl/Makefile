# Data Structures and Algorithms - Final Project
# GNU libavl
# Makefile of /ext/gnu_avl
#
# Make sure $(GNUAVL) is set to the root of this project

export GNUAVL=$(CURDIR)

include $(GNUAVL)/Makefile.inc

SUBDIR = src

.PHONY: all $(SUBDIR) clean

all: $(SUBDIR)
	@echo > /dev/null

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
