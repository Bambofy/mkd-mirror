#!/bin/bash
# File 3-copy2man-and-doc.sh
# cp -f mkddocu_de.1.gz ../../man/de/mkddocu.1.gz
rm *~
cp -f mkddocu_en.1.gz ../../man/en/mkddocu.1.gz
cp -f mkddocu_fr.1.gz ../../man/fr/mkddocu.1.gz
cp -f *.txt.gz ../../doc/.
cp -f *.html ../../doc/html/.

