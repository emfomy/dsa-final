# Data Structures and Algorithms - Final Project
# Makefile of /src
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

SUBDIR = core account_avl_tree account_hash_map account_skip_list history_hash_map

.PHONY: all $(SUBDIR) clean

all: $(SRCDIR)
	@echo > /dev/null

$(SRCDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
