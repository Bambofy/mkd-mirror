#!/usr/bin/make
# file: Makefile for packaging mkd on debian or ubuntu sytems
# modified by Jean-Paul Louyot 2014-02-27; 2014-03-17
# 
# Copyright: ©EELL http://edeulo.free.fr/wiki/index.php/Projet_mkd#LE_DROIT_DE_COPIE:
# For local tests type command 'make -d install DESTDIR=.'
# For Debian packages : (source in mkddocu-140224/scr-mkddocu)
# pour la version binaire simple
# 	make -d install DESTDIR=../debian/mkddocu 
#	make -d -C src-mkddocu install DESTDIR=../debian/mkddocu # Pour le rep ../
# For mkd-doc_all.deb : version bin multiple
# 	make -d install DESTDIR=../debian/mkd-doc
#	make -d -C src-mkddocu install DESTDIR=../debian/mkd-doc # Pour le rep ../

# ---------------------------------------------------------------------------------------------
#
BIN   = $(DESTDIR)/usr/bin
ETC   = $(DESTDIR)/etc
DOC   = $(DESTDIR)/usr/share/doc
ICONS = $(DESTDIR)/usr/share/icons/hicolor
LANG  = $(DESTDIR)/usr/share/locale
MAN   = $(DESTDIR)/usr/share/man
MIME  = $(DESTDIR)/usr/share/mime
SRCS  = # mkddocu.sh # gettext.sh
PGM   = mkddocu

$(PGM) : $(SRCS)
	mkd -twC C mkddocu.sh mkddocu
	chmod 755 mkddocu

install : $(PGM)
	# create for tests $(DESTDIR) and copy executable in bin directory:
	install -d $(BIN) $(DOC) $(ICONS) $(LANG) $(MAN) $(MIME)
	install $(PGM) $(BIN)/.
	# install docs:
	install -d $(DOC)/$(PGM)/html
	install -m644 doc/*.txt.gz $(DOC)/$(PGM)/.
	install -m644 doc/html/*.html $(DOC)/$(PGM)/html/.
	# install icons and update cache: see update in post-install package
	# install -d $(ICONS)/256x256/apps $(ICONS)/48x48/apps $(ICONS)/32x32/apps $(ICONS)/16x16/apps
	chmod 644 icons/*
	# cp -f icons/mkd-128x128.png $(ICONS)/128x128/apps/mkd.png
	# cp -f icons/mkd-256x256.png $(ICONS)/256x256/apps/mkddocu.png
	# cp -f icons/mkd-48x48.png $(ICONS)/48x48/apps/mkddocu.png
	# cp -f icons/mkd-32x32.png $(ICONS)/32x32/apps/mkddocu.png
	# cp -f icons/mkd-16x16.png $(ICONS)/16x16/apps/mkddocu.png
	#T if [ -e "/usr/share/icons/hicolor/16x16/apps/mkddocu.png" ]; then \
		#T gtk-update-icon-cache -t /usr/share/icons/hicolor; fi
	# if test $(DESTDIR); then echo "DESTDIR is not empty"; \
	# else gtk-update-icon-cache -t /usr/share/icons/hicolor; fi
	## install software messages :
	# Installs for tests the local languages, 'de', 'es', 'fr', it, ro, etc.:
	install -d $(LANG)/en/LC_MESSAGES $(LANG)/de/LC_MESSAGES $(LANG)/fr/LC_MESSAGES
	# pas traduit ! cp -f lang/po/mkddocu_en.mo $(LANG)/en/LC_MESSAGES/mkddocu.mo
	cp -f locale/mkddocu_fr.mo $(LANG)/fr/LC_MESSAGES/mkddocu.mo
	# install manuals:
	## install default manual:
	install -D -m644 man/en/mkddocu.1.gz $(MAN)/man1/mkddocu.1.gz
	## install 'de' manual:	
	# install -d $(MAN)/de/man1
	# cp -f man/de/mkd.1.gz $(MAN)/de/man1/mkd.1.gz
	## install 'fr' manual: UTF8 n'est pas standard sur tous les linux !
	install -d $(MAN)/fr/man1
	cp -f man/fr/mkddocu.1.gz $(MAN)/fr/man1/mkddocu.1.gz
	# install and update MIME database: see update in post-install package
	install -D -m644  mime/mkddocu.xml $(MIME)/packages/mkddocu.xml
	if test $(DESTDIR); then echo "DESTDIR is not empty mime database is not updated"; \
	else update-mime-database /usr/share/mime/; fi

clean:
	# rm *~
