#!/bin/bash
# File test.sh
# sytaxe : sudo test.sh
# après installation vérifier que le type reconnu est text/plain; charset utf-8
clear
echo "liste des fichiers mime mkd* présents avant l'installation :"
ls /usr/share/mime/packages/mkd*                                                                  
# supprimer les anciens fichiers mkd.xml mkddocu si ils existent
if test "/usr/share/mime/packages/mkd.xml"; then rm -f /usr/share/mime/packages/mkd.xml; fi
if test "/usr/share/mime/packages/mkddocu.xml"; then rm -f /usr/share/mime/packages/mkddocu.xml; fi
# install and update MIME database: see update in post-install package
install -D -m644  mkd.xml /usr/share/mime/packages/mkd.xml
echo "liste des fichiers mime mkd* présents après l'installation :"
ls /usr/share/mime/packages/mkd*  
echo "mise à jour de la base"                                                                
if test "/usr/share/mime/packages/mkd.xml"; then update-mime-database /usr/share/mime/; fi
# test
echo "Vérifier la reconnaissance du type *.prj"
file --mime ../project.prj
echo "tous :"
file ../*
echo -n "CTRL-C or Return to quit : "
read i
