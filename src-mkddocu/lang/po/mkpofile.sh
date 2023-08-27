#!/bin/bash
# File mkpofile
# ../../mkddocu.sh est le fichier qui contient ". gettext.sh"
# TEXTDOMAIN=mkddocu # TEXTDOMAIN=@PACKAGE@
# export TEXTDOMAIN
# TEXTDOMAINDIR=~ # TEXTDOMAINDIR=@LOCALEDIR@
# export TEXTDOMAINDIR
# Ca donne ~/mkddocu ?
#
# On pourrait aussi utiliser ~/.local/share/locale
#
# pour l'affichage une foi intallé:
# TEXTDOMAIN=im-config
# TEXTDOMAINDIR=/usr/share/locale/
# LANG=fr_FR.UTF-8
# LANGUAGE=fr_FR
 xgettext -L shell -o ./mkddocu.po --from-code=UTF-8 ../../mkddocu.sh
# xgettext -L shell -o ./mkddocu.po --no-location --from-code=UTF-8 ../../mkddocu.sh
# xgettext -L shell -o ./mkddocu.po ../../mkddocu.sh
echo " appuyer sur une touche pour lancer gettext CTRL-C si non."
read inkey
poedit mkddocu.po
exit 0

