#!/bin/bash
echo "File UNINSTALL.sh in src-mkddocu directory."
echo "rm /usr/bin/mkddocu"
rm -f /usr/bin/mkddocu
echo "/usr/share/doc/mkd"
rm -Rf /usr/share/doc/mkd
# Note : les icônes de mkddocu n'existent pas ... Voir mkd
# rm -f /usr/share/icons/hicolor/128x128/apps/mkddocu.png
# Note : l'application est écrite en anglais-us
echo "rm sofware messages"
rm -f /usr/share/locale/fr/LC_MESSAGES/mkddocu.mo
echo "rm manuals"
rm -f /usr/share/man/man1/mkddocu.1.gz
rm -f /usr/share/man/fr/man1/mkddocu.1.gz
rm "erase mkddocu informations from the mime-database"
rm -f /usr/share/mime/packages/mkddocu.xml
update-mime-database /usr/share/mime/
echo "UNINSTALL mkddocu End"
