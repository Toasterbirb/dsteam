# dsteam - dynamic steam game launcher
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c dsteam.c util.c
OBJ = $(SRC:.c=.o)

all: options dsteam

options:
	@echo dsteam build options:
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

.c.o:
	$(CC) -c $(CFLAGS) $<

config.h:
	cp config.def.h $@

$(OBJ): arg.h config.h config.mk drw.h

dsteam: dsteam.o drw.o util.o
	$(CC) -o $@ dsteam.o drw.o util.o $(LDFLAGS)

clean:
	rm -f dsteam $(OBJ) dsteam-$(VERSION).tar.gz

dist: clean
	mkdir -p dsteam-$(VERSION)
	cp LICENSE Makefile README arg.h config.def.h config.mk dsteam.1\
		drw.h util.h dsteam_update $(SRC)\
		dsteam-$(VERSION)
	tar -cf dsteam-$(VERSION).tar dsteam-$(VERSION)
	gzip dsteam-$(VERSION).tar
	rm -rf dsteam-$(VERSION)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f dsteam dsteam_update $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dsteam
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dsteam_update
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < dsteam.1 > $(DESTDIR)$(MANPREFIX)/man1/dsteam.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/dsteam.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dsteam\
		$(DESTDIR)$(PREFIX)/bin/dsteam_update\
		$(DESTDIR)$(MANPREFIX)/man1/dsteam.1\

.PHONY: all options clean dist install uninstall
