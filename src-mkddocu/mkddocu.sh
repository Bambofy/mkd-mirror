#!/bin/bash
#P File mkddocu writed by Clara Jimenez 2013-12-15
#P Fichier modifié par JPL le 22/02/2014 pour une version plus universelle
#P mkddocu.sh modifié le 22/03/2014 par JPL pour introduire l'icône mkd dans 
#P    ~.icons de l'utilisateur pour identifier le fichier .prj de mkd
#P    suppression de l'option -s pour produire le fichier des chaînes de
#P    caractères
#P Util : Create any debian package for mkd for multi-lang programming languages
#P modifié par JPL modification des messages. ajout de (mkddocu) pour faire la 
#P    différence avec les messages de mkd et invalidation pour gettext des
#P    messages qui ne supportent pas le traduction tel que ./maintenance/Backup
#P
#
#D Fichier mkddocu.sh
#D -----------------------------------------------------------------------------
#D Documentation : Manuel mkddocu(1)
#D Cette commande doit être placée dans le répertoire /usr/bin
#D 
#D NOM
#D    mkddocu  -  Cette commande shell génère la documentation informatique de tout fichier de
#D    projet reconnu par la commande mkd
#D
#D SYNOPSYS
#D    mkddocu [nom] [s]
#D
#D DESCRIPTION
#D    La commande mkd associée à mkddocu, extrait les commentaires  dotés  d'un  caractère  de
#D    repère.
#D    Si  des  fichiers  de langage C sont présents, mkddocu génère un fichier d'entête global
#D    (header) du projet informatique.
#D
#D    Caractère de repère
#D       D - Extrait la documentation générale.
#D       T - Extrait le document des directives de tests.
#D       P - Extrait un document utile aux mainteneurs.
#D
#D OPTIONS
#D    nom    Cette option permet de choisir un nom de  projet  différent  du  nom  par  défaut
#D           project.  Si nom est le caractère '?' la commande affiche la syntaxe.
#D
#D    s      Cette  option  génère  le  fichier  des  chaînes  de caractères et le fichier des
#D           chaînes de caractères utiles aux traductions avec gettext et poedit.
#D
#D VALEURS RETOURNÉES
#D     0 : Fin normale à la fin de l'exécution de la commande.
#D     1 : Fin normale après l'affichage de la syntaxe de la commande.
#D     -1 : Erreur de sauvegarde de la série de documents dans Backups.
#D 
#D EXEMPLES :
#D    L'auto documentation de cette commande se crée  en  renommant  pour  l'usage  mkddocu.sh
#D    L'extension importe peu, la commande sera gérée par bash. Les fichiers sans extension ou
#D    avec l'extension .bash ne sont pas pris en compte.
#D    compte.
#D    Lancer la commande 'mkddocu.sh mkddocu -s'
#D    Le répertoire maintenance/mkddocu contiendra la documentation
#D    Les répertoires de projet sont générés par séries et peuvent avoir été sauvegardés  dans
#D    un répertoire Backups si le nombre de fichiers de projet de la série ont atteind la lim‐
#D    ite BACKUPSMAX
#D    Pour les essais on peut se limiter à BACKUPSMAX=2 (3 'backups' par série.)
#D
#D REMARQUES
#D    BACKUPSMAX est normalement fixé à 9 mais peut être modifié par édition du fichier.
#D
#D VOIR AUSSI 
#D    mkd(1) gettext(1) poedit(1)
#D
#D TÉLÉCHARGEMENTS
#D    http://edeulo.free.fr
#D
#D AUTEURS
#D    Clara, JPL
#D    Email : http://edeulo.free.fr/contacts/formmail.php
#D
#D BUGS
#D    Rapports de bugs : http://edeulo.free.fr/phpBB3/index.php
#D
#
#T Fichier mkddocu.sh
#T -----------------------------------------------------------------------------
#T Tests : Ne peut fonctionner que si la commande mkd est installée.
#T
#T Test unitaire :
#T ---------------
#T Renommer mkddocu mkddocu.sh ou .csh
#T Editer le fichier mkddocu.sh et modifier la valeur de BACKUPSMAX limiter 
#T cette valeur à 3 (4 sauvegardes indicées)
#T
#T La commande s'autoteste
#T 1. Lancer 4 fois la commande ./mkddoccu (sans paramètre)
#T 2. Vérifier la commande de boucle à chaque fois, elle doit incrémenter les 
#T    répertoires de projets project (le dernier), puis project.1, etc.
#T    Après project.3 on doit vous demander si vous désirez préserver ces
#T    fichiers dans un répertoire .Backups. Répondez oui : 'y' (yes)
#T 3. Vérifier que le fichier .prj prend bien en charge tous les fichiers de
#T    langages de programmation de la commande mkd. Pour cela il faut évidemment
#T    disposer des fichiers nécessaires. On peut en trouver sur le site EELL
#T    http://edeulo.free.fr/wiki/index.php/Projet_mkd/Fichiers_en_développement
#T    Les fichiers en développement sont accompagnés de leurs tests unitaires,
#T    notamment le fichier find.inc.c très sollicité par la commande mkddocu.
#T    Trouver des exemples aussi sur wikipedia, wikibooks.
#T 4. Essayer les commandes : (dans un 'Terminal' ou une 'Konsoke')
#T    ./mkddocu.sh -s
#T    ./mkddocu.sh mkddocu
#T    ./mkddocu.sh mkddocu -s
#T    ./mkddocu.sh -s mkddocu
#T    Les commandes mkd ont été éprouvées par ailleurs. Vérifiez tout de même
#T    que les fichiers générés sont bien conformes.
#T 5. Vérifiez que les fichiers en langage C sont pris en compte quand ils sont
#T    présents. les fichiers d'entête (.h) n'ont pas à être pris en compte.
#T 6. Vérifier le bon fonctionnement des traduction
#T    xgettext : Outil pour extraire les chaînes à traduire avec poedit
#T    ne pas oublier la ligne '. gettext.sh' en tête de fichier
#T    xgettext -L shell -o lang/mkddocu.po --from-code=UTF-8 mkddocu.sh
#T
#T Après modification de la syntaxe, vérifier la nécessité de donner le nom du 
#T    répertoire de sauvegarde en paramètre.
#T 
#T
#T Tests d'intégration :
#T ---------------------
#T Pour ces tests il faut évidemment disposer de vrais fichiers de programmation
#T dans différent langages mais cela a déjà été fait lors des tests
#T d'intégration de la commande mkd.
#T On peut trouver ces fichiers dans chaqu'un des fichiers de tests unitaires de
#T la page wiki 'fichiers' en développement citée plus haut.
#T
#
#
#P Fichier mkddocu.sh
#P -----------------------------------------------------------------------------
#P Menu d'aide sommaire obtenu par la commande 'mkddocu ?'
#
#P Extract code mkd -twC C mkddocu.sh mkddocu 
# /*C#!/bin/bash
#P File mkddocu
. gettext.sh
#
if ! test ~/.icons/mkd.png ; then
   install -D -m644 /usr/share/icons/hicolor/128x128/apps/mkd.png \
   ~/.icons/mkd.png
fi
if test -x /usr/bin/mkd; then echo "";
else
   if test -x ./mkd ; then echo "";
   else 
      echo "$(gettext ' Please install mkd software ')" 
      exit -1 #P exit -1 : La commande mkd n'est pas trouvée
   fi
fi
#
#P -----------------------------------------------------------------------------
#P Gestion de la syntaxe Nouvelle version pour mkd 140515
#
#P Créer la fonction d'affichage 'syntaxe'.
function put_syntaxe
{
      echo "$(gettext ' Syntax : ')"
      echo "$(gettext ' mkddocu <target_dir> ')"
      echo "$(gettext '    -> example of series with date : mkddocu 2014-02-22 ')"
      echo "$(gettext '    The target directory is also writen in maintenance directory : ')"
      echo "$(gettext '    -> maintenance/2014-02-22/ ')"
      echo "$(gettext ' mkddocu ? for this help ')"
      echo ""
}
#
if ! test $1; then put_syntaxe; exit -3; fi #P exit -3 : défaut de param d'entrée
if test $1; then
   if [ $1 = "?" ]
   then
      put_syntaxe
      exit 0 #P exit 0 : Fin d'affichage de la syntaxe
   fi
fi
#P Affecttion des macros et des variables
#P    BACKUPSMAX : Définition du nombre de sauvegardes d'une série avant la 
#P     sauvegarde globale dans un répertoire 'Backup'. (Valeur modifiable)
BACKUPSMAX=10 
let i=1           #P compteur
str="false"       #P false ou true
project="project" #P nom du fichier de projet .prj
#
#P -----------------------------------------------------------------------------
#P Gestion des paramètres d'entrée
#
if test $1; then
   if test $2; then
      echo ""
#      echo " Deux paramètres à la ligne de commande "
#      echo " Paramètres : 1=$1, 2=$2 "
      if test $1 && [ $1 != "-s" ] ; 
      then 
         project=$1; 
         if [ $2 = "-s" ]; then str="true"; fi #P Vérif que c'est bien -s
      else 
         if [ $1 = "-s" ]; then str="true"; project=$2; fi
      fi
   else
      echo ""
#      echo " Un seul paramètre à la ligne de commande : $1 "
      if test $1 && [ $1 != "-s" ] ; then project=$1; fi #T ancienne version 140315
      #w if [ $1 = "-s" ]; then str="true"; fi
      if [ $1 = "-s" ]; then put_syntaxe; exit -3; fi #T version 140515
   fi
else echo "" # " Pas de paramètre "
fi
#P force str="true" without option -s 22/03/2014
str="true" #P
# echo " Projet : $project "
# echo " Strings ? : $str "
#
#P -----------------------------------------------------------------------------
#P Gestion de sauvegarde des séries (Transfert dans maintenance/Backup)
#
#P Créer la fonction 'sauvegarde'. (Noter que la varable i est globale)
function sauvegarde
{
   if test -d maintenance/$project 
   then
   mv maintenance/$project maintenance/$project.$i
   fi
}
#Po Tant que l'on n'a pas atteind BACKUPSMAX
    while ((i<=BACKUPSMAX)); 
    do
#Po   Si le répertoire de projet.i existe
      if test -d maintenance/$project.$i
#Po   alors:
      then 
#Po      Si le nombre de répertoires projet.i de la série dépasse BACKUPSMAX
         if [ $i = $BACKUPSMAX ]
         then 
#Po         demander si il faut transférer la série dans de répertoire 'Backup'
            echo -n " (mkddocu) "
            echo "$(gettext ' Last backup before maintenance : ')"
            echo -n " (mkddocu) "
            echo -n "$(gettext ' Make backup in Backups dir, yes ? Your choice : y ? ')"
            read char
#Po         si 'y' (yes)
            if test $char &&  [ $char = "y" ]
#Po         alors:
            then 
#Po            Créer le répertoir Backup s'il y a lieu et transférer la série .*
               echo ""
               echo -n " (mkddocu) "
               echo -n "$(gettext ' If the directory ')"
               echo -n "'Backups'"
               echo "$(gettext ' does not exist, create it ')"
               install -d Backups
               ((i++))
               sauvegarde
               cp -rf  maintenance/$project.* Backups/.
               rm -rf maintenance/$project.*
               clear
               echo -n " (mkddocu) "
               echo -n "$(gettext ' Files in directory ')"
               echo "Backups "
               ls -al Backups
            else 
               echo -n " (mkddocu) "
               echo "$(gettext ' return -2 ')"
               exit -2 #P exit -2 : Fin par erreur ou abandon de l'utilisateur
            fi
         fi
#Po    sinon: Sauvegarder le dernier répertoire par incrément d'extension
      else 
         sauvegarde
      fi
      let i++
      #break
   done
#
#P -----------------------------------------------------------------------------
#P Préparation des répertoires de travail, maintenance et fichier de projet .prj
#
#P    Clean, nettoyage des fichiers d'éditions *~
      rm *.c~ #w ATTENTION ! à exécuter avec précaution
#P    Créer du répertoire ./maintenance si il n'existe pas
      install -d maintenance/$project
#P    Créer le fichier de projet .prj pour tout langage de programmation
      rm -f *.prj
      ls -1 *.asm *.s *.bas *.vb *.bat *.c *.C *.h *.H *.D *.cc *.hh *.cp *.cs \
      *.c# *.c++ *.h++ *.c-- *.h-- *.cpp *.hpp  *.css *.pr *.pl *.php *.jav \
      *.jse *.js  *.f99 *.f *.pas *.p *.sh *.csh *.pl, *.rb *.py *.pyw *.pj \
      *.prj > $project.prj > /dev/null
#
#P -----------------------------------------------------------------------------
#P Génération de la documentation :
#
#P    Générer le fichier d'entête global .h si il existe des fichiers .c??
ls *.c* *.C* > cfiles.txt
if test -s cfiles.txt ; then cfiles="true"; fi
rm -f cfiles.txt
if test $cfiles; then
   echo -n " (mkddocu) "
   echo -n "$(gettext ' -> Create header file in ')"
   echo -n "maintenance/$project/$project.h"
   echo "$(gettext ' (benchmark H) ')"
   mkd -Cjt H $project.prj ./maintenance/$project/$project.h 
#Pw   -> Remarque d'ATTENTION pour copier manuellement le fichier d'entête .h
   echo -n " (mkddocu) "
   echo "$(gettext ' -> Warning : Copy manually the header file in current source directory ')"
#Pw   -> ATTENTION ligne non validée : cp -f ./maintenance/$project/$project.h . 
else 
   echo -n " (mkddocu) "
   echo "$(gettext ' C files not found ')"
fi
#
#en   Make documentation with benchmark 'D'
#P    Générer la 'documentation' avec le repère 'D'
#
echo -n " (mkddocu) "
echo "$(gettext ' Creating documentation, find the programming style, with the benchmark D ')"
echo " -> ./maintenance/$project/$project-documentation.txt "
mkd -fjt D $project.prj ./maintenance/$project/$project-documentation.txt
#
#en   Make individuals tests directives document; style find add number of lines
#P    Générer le fichier des directives des tests; avec numéro de ligne repère 'T'
#
echo -n " (mkddocu) "
echo "$(gettext ' Creates the tests document and the directives of tests, with the benchmark T ')"
echo " -> ./maintenance/$project/$project-tests-directives.txt "
mkd -fjnt T $project.prj ./maintenance/$project/$project-tests-directives.txt
#
#en   Make maintainers documentation, add line number, benchmark 'P'
#P    Générer le fichier destiné aux mainteneurs avec le repère 'P'
#
echo -n " (mkddocu) "
echo "$(gettext ' Creates the document for the maintainers, with the benchmark P ')"
echo " -> /maintenance/$project-maintainers-doc.txt "
mkd -fjnt P $project.prj ./maintenance/$project/$project-maintainers-doc.txt
#
#P Si le paramètre '-s' est entrée à la commande:
#P    Créer les fichiers : chaînes de caractères et chaînes pour gettext
#en If second parametre is "-s" then
#en   Get all strings and select strings for translations
#
if [ $str = "true" ]; then
   echo -n " (mkddocu) "
   echo "$(gettext ' Creates a file with strings, and a file with strings for tranlations, with benchmark ** ')"
   mkd -fpnjs '**' $project.prj ./maintenance/$project/strings.txt | \
   grep gettext > ./maintenance/$project/strings-2-translations.txt 
fi
#
#P -----------------------------------------------------------------------------
#P Afficher les recommandations de lecture des fichiers de maintenance
#
echo -n " (mkddocu) "
echo -n "$(gettext '  See in working directory: ')"
echo "./maintenance/$project/$project/* "
ls -l ./maintenance/$project
#P Quitter avec un retour à la valeur 0 Fin correcte normale
echo -n " (mkddocu) "
echo "$(gettext '  end normal, return 0 ')"
exit 0 #P exit 0 : Fin d'exécution de la commande mkddocu
#*/

