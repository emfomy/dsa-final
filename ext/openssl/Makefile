# Data Structures and Algorithms - Final Project
# OpenSSL
# Makefile of /ext/openssl
#
# Make sure $(DSA) is set to the root of this project

include $(DSA)/Makefile.inc

SUBDIR =

.PHONY: all $(SUBDIR) clean

all: $(SUBDIR)
	@echo > /dev/null

$(SUBDIR):
	@( cd $@ ; $(MAKE) all )

clean:
	@for dir in $(SUBDIR); do ( cd $$dir ; $(MAKE) clean ) done
