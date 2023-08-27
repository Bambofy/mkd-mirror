#!/bin/bash
# File testmanuals.sh
rm *~
echo " test des manuels "
# (en)
# LANG=en_GB man 1 mkddocu # LANG à identifier ... pas de manuel spécifique → man std
man ./mkddocu_en.1.gz
#
# (fr)
# LANG=fr_FR.UTF-8 man 1 mkddocu
man ./mkddocu_fr.1.gz
#
echo " fin des tests " 
