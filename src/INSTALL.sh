#!/bin/sh
# file INSTALL.sh for mkd (Unix command)
# install mkd files
# syntax :  "sudo ./INSTALL.sh" 
# or "./INSTALL.sh .." before packaging
# or "./INSTALL.sh ../test-INSTALL-SH" for tests
# ATTENTION : this shell command cannot install mkd in /usr/local/

rm -f mkd

# for tests
if test $1; then echo "test directory : $1"; \
rm -Rf $1 ;
install -d $1/etc \
$1/var/cache/man \
$1/usr/bin \
$1/usr/share/doc/mkd/html \
$1/usr/share/icons/hicolor/16x16/apps \
$1/usr/share/icons/hicolor/32x32/apps \
$1/usr/share/icons/hicolor/48x48/apps \
$1/usr/share/icons/hicolor/128x128/apps \
$1/usr/share/icons/hicolor/256x256/apps \
$1/usr/share/locale/de/LC_MESSAGES \
$1/usr/share/locale/fr/LC_MESSAGES \
$1/usr/share/locale/en/LC_MESSAGES \
$1/usr/share/man/man1 \
$1/usr/share/man/man3 \
$1/usr/share/man/de/man1 \
$1/usr/share/man/fr.UTF-8/man1 \
$1/usr/share/man/fr/man1 \
$1/usr/share/mime/packages
fi

#
# Compil mkd, install and clean
#
echo "########### VERIFY  C files ###########"
# make -f unix.mak lint
# echo "STRIKE 'RETURN' TO CONTINUE   'CTRL-C' FOR EXIT"
# read $key

echo "############# INSTALL mkd #############"
make -f unix.mak
# echo "STRIKE 'RETURN' TO CONTINUE   'CTRL-C' FOR EXIT"
# read $key

echo "################ CLEAN ################"
make -f unix.mak clean
# echo "STRIKE 'RETURN' TO CONTINUE   'CTRL-C' FOR EXIT"
# read $key
clear

echo "### INSTALL BIN, MAN, LANG, ICON, and MIME DATABASE, ON UBUNTU or DEBIAN ###"
# echo "STRIKE 'RETURN' TO CONTINUE   'CTRL-C' FOR EXIT"
# read $key
clear
#
# install bin
#
echo "install or update mkd bin on UBUNTU or DEBIAN"
echo "install bin mkd compiled with UTF-8 format"
chmod 755 mkd
 rm -f $1/usr/local/bin/mkd
 cp -f mkd $1/usr/bin/mkd
#
# install manuals
#
echo "erase old mkd manual mkd 1"
if [ -e "/usr/local/man/mkd.1.gz" ]; then  rm -f $1/usr/local/man/mkd.1.gz ; fi
if [ -e "/usr/local/man/man1/mkd.1.gz" ]; then  rm -f $1/usr/local/man/man1/mkd.1.gz ; fi
if [ -e "/usr/share/man/man1/mkd.1.gz" ]; then  rm -f $1/usr/share/man/man1/mkd.1.gz ; fi
#
echo "install or update mkd manual mkd 1"
chmod 644 man/en/mkd.1.gz
chmod 644 man/fr/mkd.1.gz
chmod 644 man/de/mkd.1.gz
#
echo " Manual mkd(1) and cpp(3), us-ascii by default"
 cp -f man/en/mkd.1.gz $1/usr/share/man/man1/mkd.1.gz ;
 cp -f man/en/cpp.3.gz $1/usr/share/man/man3/cpp.3.gz;
# echo " For language British"
# if [ -d "/usr/share/man/en_GB/man1" ]; \
#	then  cp -f lang/man/en_GB/mkd.1.gz $1/usr/share/man/en_GB/man1/mkd.1.gz ; \
# fi
echo " Handbuch für die deutsche Sprache"
# Debian install :
# if [ -d "/usr/share/man/de.UTF-8/man1" ]; \
#	then  cp -f man/de/mkd.1.gz $1/usr/share/man/de.UTF-8/man1/mkd.1.gz ; \
#	elif [ -d "/usr/share/man/de/man1" ]; then  cp -f man/de/mkd.1.gz $1/usr/share/man/de/man1/mkd.1.gz ; \
# fi
# Universal install :
cp -f man/de/mkd.1.gz $1/usr/share/man/de/man1/mkd.1.gz
#
echo " Manuel pour la langue française"
# Debian install :
# if [ -d "/usr/share/man/fr.UTF-8/man1" ]; \
#	then cp -f man/fr/mkd.1.gz $1/usr/share/man/fr.UTF-8/man1/mkd.1.gz ; \
#	elif [ -d "/usr/share/man/fr/man1" ]; then  cp -f man/fr/mkd.1.gz $1/usr/share/man/fr/man1/mkd.1.gz ; \
# fi
# Universal install :
cp -f man/fr/mkd.1.gz $1/usr/share/man/fr/man1/mkd.1.gz
#
# install messages 
#
echo "install or update soltware messages"
chmod 644 locale/*.mo
#
if [ -f "locale/mkd_de.mo" ] ; then \
		echo " (de) mkd.mo" ; \
		 cp -f locale/mkd_de.mo $1/usr/share/locale/de/LC_MESSAGES/mkd.mo ; \
fi
#
if [ -f "locale/mkd_en.mo" ] ; then \
		echo " (en) mkd.mo" ; \
		 cp -f locale/mkd_en.mo $1/usr/share/locale/en/LC_MESSAGES/mkd.mo ; \
fi
#
if [ -f "locale/mkd_fr.mo" ] ; then \
		echo " (fr) mkd.mo" ; \
		 cp locale/mkd_fr.mo $1/usr/share/locale/fr/LC_MESSAGES/mkd.mo ; \
fi
#
# install doc text and html
#
echo "install or update text and html doc"
chmod -f 644 doc/*.gz doc/html/*.html
cp -Rf doc/* $1/usr/share/doc/mkd/.
#
# install icons 
# SEE mkddocu
#
echo "install or update icons" # to "$1"/usr/share/icons/hicolor/"
	# rm -f $1/usr/share/icons/hicolor/256x256/apps/mkd.png
	cp -f icons/mkd-256x256.png $1/usr/share/icons/hicolor/256x256/apps/mkd.png
	# rm -f $1/usr/share/icons/hicolor/128x128/apps/mkd.png
	cp -f icons/mkd-128x128.png $1/usr/share/icons/hicolor/128x128/apps/mkd.png
	# rm -f $1/usr/share/icons/hicolor/48x48/apps/mkd.png
	cp -f icons/mkd-48x48.png $1/usr/share/icons/hicolor/48x48/apps/mkd.png
	# rm -f $1/usr/share/icons/hicolor/32x32/apps/mkd.png
	cp -f icons/mkd-32x32.png $1/usr/share/icons/hicolor/32x32/apps/mkd.png
	# rm -f $1/usr/share/icons/hicolor/16x16/apps/mkd.png
	cp -f icons/mkd-16x16.png $1/usr/share/icons/hicolor/16x16/apps/mkd.png
	if $1; then
		echo "icon cache is not updated see debian/postinst"
	elif test "/usr/share/icons/hicolor/16x16/apps/mkd.png"; then
		echo "update icon-cache" ;
		gtk-update-icon-cache -t /usr/share/icons/hicolor; 
	fi
#
# update mime database for mkd 
# SEE src-mkddocu
#
# Copy mkd.xml for packaging or verify in tests directory
	echo "Copy mime package in "$1
	cp -f mime/mkd.xml $1/usr/share/mime/packages/.
# if /usr/share/mime/packages/mkd.xml exist then update database
	if $1; then
		echo "mime database is not updated see debian/postinst";
 	elif test "/usr/share/mime/packages/mkd.xml"; then
		echo "Update mime database mkd";
		update-mime-database /usr/share/mime ; 
	fi

# =====
# Errors concerning other packages : test in verbose mode.
#  update-mime-database -V /usr/share/mime
# Unknown media type in type 'all/all'
# Unknown media type in type 'all/allfiles'
# Unknown media type in type 'uri/mms'
# Unknown media type in type 'uri/mmst'
# Unknown media type in type 'uri/mmsu'
# Unknown media type in type 'uri/pnm'
# Unknown media type in type 'uri/rtspt'
# Unknown media type in type 'uri/rtspu'
# Unknown media type in type 'interface/x-winamp-skin'
echo "End update"

# ./post_install_tests
