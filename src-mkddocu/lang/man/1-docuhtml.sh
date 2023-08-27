#!/bin/sh
# File docuhtml.sh
# nécessité de les créer ici pour tester
# compression des manuels
gzip -vkf *.1 
# doc (en)
# création de la doc texte brute
man ./mkddocu_en.1.gz > mkddocu_en.txt
# création de la doc (en) html
man2html mkddocu_en.1.gz > mkddocu_en.html
#
# doc (fr)
# création de la doc texte brute
man ./mkddocu_fr.1 > mkddocu_fr.txt
# création de la doc (fr) html
echo "<meta charset=\"utf-8\">" > mkddocu_fr.html
man2html mkddocu_fr.1.gz >> mkddocu_fr.html
#
# compression de la doc texte
gzip -vkf *.txt
#
# nettoyage
rm -f *.txt
