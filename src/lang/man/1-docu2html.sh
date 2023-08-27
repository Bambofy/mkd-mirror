#!/bin/sh
# File docu2html.sh
# ATTENTION éditer les manuels uniquement avec gedit !
rm *.gz
#
# man (1)
#
rm *~
# Compress the .1 files
gzip -vkf *.1 # → *.1.gz
# Create text and UTF-8 html (de) manual
man ./mkd_de.1.gz > mkd_de.txt
echo "<meta charset=\"utf-8\">" > mkd_de.html
man2html mkd_de.1.gz >> mkd_de.html
# Create plain text and ASCII html (en) manual
# Create plain text and utf-8 html (en) manual
man ./mkd_en.1.gz > mkd_en.txt
echo "<meta charset=\"utf-8\">" > mkd_en.html
man2html mkd_en.1.gz >> mkd_en.html
# CReate text and UTF-8 html (fr) manual
man ./mkd_fr.1.gz > mkd_fr.txt
echo "<meta charset=\"utf-8\">" > mkd_fr.html
man2html mkd_fr.1.gz >> mkd_fr.html
#
# man (3)
#
# Compress the .3 files
gzip -vkf *.3 # → *.3.gz
# Create plain text and ASCII html (en) manual
man ./cpp_en.3.gz > cpp_en.txt
man2html cpp_en.3.gz > cpp_en.html
#
# Copy to doc files
#
install -d ../../doc/html
gzip -vkf *.txt
chmod 644 *.gz *.html
cp -f *.txt.gz ../../doc/.
rm -f *.txt
cp -f *.html ../../doc/html/.
cp -f mkd_de.1.gz ../../man/de/mkd.1.gz
cp -f mkd_en.1.gz ../../man/en/mkd.1.gz
cp -f mkd_fr.1.gz ../../man/fr/mkd.1.gz
read inkey
