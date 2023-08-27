#!/bin/bash
# File testmanuals.sh
clear
# echo " NOTE POST-INSTALL : (Ne concerne pas les manuels non ré-installés)"
# echo " en cas de différence entre le manuel installé et les fichiers locaux, "
# echo " il convient de lancer la commande mandb -c"
# read inkey
#
# MKD
#
# echo " Man (de) installé ← (Return) : "
# read inkey
# (de)
# LANG=de man 1 mkd_de.1.gz
echo -n " Man mkd (de) local ← (Return) : "
read inkey
man 1 ./mkd_de.1.gz
#
# (en)
# LANG=en_GB man 1 mkd # LANG à identifier ... pas de manuel spécifique → man std
echo -n " Man mkd (en) local ← : "
read inkey
man ./mkd_en.1.gz
#man --html  ./mkd_en.1.gz
#
# (fr)
# LANG=fr_FR.UTF-8 man 1 mkd
echo -n " Man mkd (fr) local ← : "
read inkey
man ./mkd_fr.1.gz
man --html  ./mkd_fr.1.gz
#
# CPP
#
# (en)
# LANG=en_GB man 3 cpp
echo -n " Man cpp (en) local ← : "
read inkey
LANG=en_GB man ./cpp_en.3.gz
#

