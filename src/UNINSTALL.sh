#!/bin/sh
# File unisntall.sh for mkd (Unix command)
# Updated and tested 19/03/2014
# command 'sudo ./uninstall'

erase_files ()
{
	# /etc
	# /var/cache/man
	echo erase $root"/bin/mkd"
	rm -f $root"/bin/mkd"
	echo erase $root"/share/doc/mkd/"
	rm -rf $root"/share/doc/mkd"
	echo erase $root"/share/icons/hicolor/16x16/apps/mkd.png"
	rm -f $root"/share/icons/hicolor/16x16/apps/mkd.png"
	echo erase $root"/share/icons/hicolor/32x32/apps/mkd.png"
	rm -f $root"/share/icons/hicolor/32x32/apps/mkd.png"
	echo erase $root"/share/icons/hicolor/48x48/apps/mkd.png"
	rm -f $root"/share/icons/hicolor/48x48/apps/mkd.png"
	echo erase $root"/share/icons/hicolor/256x256/apps/mkd.png"
	rm -f $root"/share/icons/hicolor/256x256/apps/mkd.png"
	# $root/share/locale/de_DE/LC_MESSAGES (de, de_DE)
	echo erase $root"/share/locale/de/LC_MESSAGES/mkd.mo"
	rm -f $root"/share/locale/de/LC_MESSAGES/mkd.mo" 
	# $root/share/locale/fr_CA/LC_MESSAGES (fr, fr_CA)
	echo erase $root"/share/locale/fr/LC_MESSAGES/mkd.mo"
	rm -f $root"/share/locale/fr/LC_MESSAGES/mkd.mo" 
	# $root/share/locale/en_??/LC_MESSAGES (en, en_AU, en_GB, en_US, en_ZA)
	echo erase $root"/share/locale/en/LC_MESSAGES/mkd.mo"
	rm -f $root"/share/locale/en/LC_MESSAGES/mkd.mo" 
	echo erase $root"/share/man/man1/mkd.1.gz"
	rm -f $root"/share/man/man1/mkd.1.gz"
	# echo erase $root"/share/man/en_GB/man1/mkd.1.gz"
	# rm -f $root"/share/man/en_GB/man1/mkd.1.gz"
	echo erase $root"/share/man/de/man1/mkd.1.gz"
	rm -f $root"/share/man/de/man1/mkd.1.gz"
	echo erase $root"/share/man/fr.UTF-8/man1/mkd.1.gz"
	rm -f $root"/share/man/fr.UTF-8/man1/mkd.1.gz"
	echo erase $root"/share/man/fr/man1/mkd.1.gz"
	rm -f $root"/share/man/fr/man1/mkd.1.gz"
	echo erase $root"/share/doc/mkd/"
	rm -Rf $root"share/doc/mkd"
	echo erase $root"/share/doc-base/mkd"
	rm -f $root"share/doc-base/mkd"
	# update mime database if mkd.xml exist in /usr/share/mime/packages/
	if test -e "/usr/share/mime/packages/mkd.xml"; then \
		echo erase "/usr/share/mime/packages/mkd.xml" ; \
		rm -f "/usr/share/mime/packages/mkd.xml" ;\
		echo "Update mime package without mkd.xml" ;
		update-mime-database "/usr/share/mime" ; 
	fi
	if ! test -e "/usr/share/icons/hicolor/16x16/apps/mkd.png"; then \
		gtk-update-icon-cache -t /usr/share/icons/hicolor; 
	fi
		echo " ==========================="
		echo " END erase mkd in "$root"/* " ;
		echo " ==========================="
}

echo " ==========================="
echo " uninstal mkd (unix command)"
echo " ==========================="
# Test after install in `../usr' directory
# last test 19/03/2014
# root="../usr"
#	echo " erase mkd in "$root"/* " ;
#	echo " ===================="
#	erase_files $root
# exit
# End test
root="/usr" ; 
echo " test if mkd is in /usr/bin"
if test -e $root"/bin/mkd"; \
	then \
		echo " erase mkd in "$root"/* " ;
		echo " ===================="
		erase_files $root
	else \
		echo " mkd is not in "$root"/bin/" ;
fi

unset root
root="/usr/local"
echo " test if mkd is in /usr/local/bin"
if test -e "/usr/local/bin/mkd"
	then \
		echo " erase mkd in "$root"/* " ;
		echo " ================================"
		erase_files $root
	else \
		echo " mkd is not in "$root"/bin/" ;
		echo " =======================" ;
		echo " exit without installing"
		echo " =======================" ;
fi


