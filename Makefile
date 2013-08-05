# Makefile for vcsadump
# (c) 2003 Florian <petafrog@evilemail.com>

CC=gcc
CFLAGS=-O2

# Where you want it installed
INSTALL_DIR=/usr/local/bin

# see README if you want to install vcsa with the setuid bit set.
INSTALL_OWNER=vcsa
INSTALL_GROUP=bin
INSTALL_MODE=4111

VERSION=1.0

all: vcsadump

clean:
	rm -f vcsadump colortest vcsadump-*.tar.gz

install:
	install -s vcsadump $(INSTALL_DIR)

install-suid:
	install -s \
		-o $(INSTALL_OWNER) -g $(INSTALL_GROUP) -m $(INSTALL_MODE) \
		vcsadump $(INSTALL_DIR)

colortest: colortest.c
	$(CC) $(CFLAGS) -o $@ $< -lncurses

dist: clean
	cd .. && \
	ln -s vcsadump vcsadump-$(VERSION) && \
	tar chzvf vcsadump/vcsadump-$(VERSION).tar.gz \
		--exclude CVS --exclude '.*' \
		--exclude '*.tar.gz' \
		vcsadump-$(VERSION)/ && \
	rm -f vcsadump-$(VERSION)
	cp -f README vcsadump-$(VERSION).tar.gz /home/tt/html/vcsadump/
