��    L      |  e   �      p     q     �     �     �     �  B   �  C     I   [  8   �  @   �  -        M     j     �     �     �     �  
   �  -   	  K   5	     �	      �	     �	     �	  0   �	  *   "
  *   M
     x
     �
     �
  C   �
     �
  "        8     G     _     h  
   q     |      �     �     �     �     �        "     1   A  #   s  /   �     �     �     �  4   	  5   >     t  %   |  1   �  1   �       )     ;   7  +   s  2   �     �      �          %  %   C  )   i  +   �  #   �  %   �  $   	     .  E   D  h  �     �               -     H  K   `  K   �  P   �  <   I  D   �  A   �       )   *     T     s     �  !   �  
   �  B   �  W     %   v  4   �  %   �     �  L     /   Z  /   �     �  "   �     �  _   	  +   i  .   �     �     �  
   �  
          ;     2   T     �     �  #   �  $   �  %   �  -      6   .  &   e  6   �     �  2   �  %   �  4   %  5   Z     �  ,   �  ;   �  ;        =  7   D  C   |  0   �  B   �     4  #   I  5   m  $   �  .   �  :   �  ;   2  (   n  *   �  -   �     �  D               
   ,          G   >   D   !   ?   .   &                        C       5       I       ;   $       E   0         	      2   8   :            "   @             #      *   4   H       %               K   '   9                 =   +          7      -                    A          F      /              <   6         (      L              1   J       B       3   )    

(file %s :)
 

DOC %s END
 

file for doc: '%s'
 

file for doc: '%s' 
 
 OVERWRIT '%s' ...  y?
                   page:  (compil.: begin with %c and end with %c)
                  example codes = UM or *OPTw or *HOS or ** for all
                  example codes = UM or \*OPTw or '* HOS' or '**' for all
           find language ( .ASM .BAS .C .FOR .PAS .PRO )
           find language ( .s .S .c .h .i .f .F .r .p .sh .csh )
       -A decode Assembler comment style only
       -B        Basic style
       -C        C++ style
       -F        Fortran style
       -P        Pascal style
       -S        Shell style
       -a append target file
       -f:
       -j use only with project sources file.
       -l and p;   line:  (compil.: %c or %c in first column or %c in line)
       -n insert line number
       -s copy and add to screen
       -t copy the comment only
       -v verbose
       -w overwrite (default option: switch off)
     or: mkd ? .See also mkd.doc or manual.     or: mkd \? .See also nanual: 'man mkd'  (5 char max)
  --> char_codes: all ASCII   --> options:
  --> path_source: source file (option j: if it is a project file) 
  --> path_target: target file
  A or B or C or...please.
.Exit 2
 %s
(file %s :) %s is write protected.
 .Exit 1
 .Exit 2
 ASSEMBLER
 Arg. syntax error '\:'
.Exit 2
 Arg. syntax error '\:'
.Exit 2 
 BASIC
 C
 Closure '%s' error
.Exit 2
 Closure error: '%s'
.Exit 2
 Closure error: '%s'
.Exit 2 
 Error, language not determined !.
 Error, programming language not found !.
.Exit 2
 Example: mkd -Cs *Snv file.c *.str
 Example: mkd -Csnv '*S' file.c \*.verif_struct
 FORTRAN
 Force language comment, style  Options a or w please...  Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d
 PASCAL
 Path target: suffixe not determined.
 Path_target: syntax error at or near '/'
.Exit 2
 Path_target: syntax error at or near '\'
.Exit 2
 SHELL
 Syntax error '*' in path_source.
.Exit 2
 Syntax error: (path_source : '%s') == (path_target = '%s')
 Syntax error: Too many 'Language' options:
 Syntax error: path_source, suffixe '.doc'
.Exit 2
 doc file : '%s' 
 error option -a or -w not found
 except space:' '  (5 char max)
 file '%s' not found for read
 file '%s' not found for read
.Exit 2
 fopen file '%s' error for append
.Exit 2
 fopen file '%s' error for overwrit
.Exit 2
 mkd PC version, Release %s, USAGE:
 mkd UNIX version, Release %s, USAGE:
 project file '%s' not found
.Exit 2
 project file : '%s' 
 syntax: mkd [-ABCFPSafjlnpstvw] char_codes path_source [path_target]
 Project-Id-Version: mkd 12.03
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2012-03-31 16:31+0200
PO-Revision-Date: 2012-03-31 18:00+0100
Last-Translator: Jean-Paul Louyot <jeanpaullouyot@free.fr>
Language-Team: French
Language: fr
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=2; plural=(n > 1);
 

(fichier %s :)
 

DOC %s FIN
 

fichier pour doc: '%s'
 

fichier pour doc: '%s' 
 
 ECRASER '%s' ...  y?
                   page:  (compil.: commence avec %c et se termine avec %c)
                  exemple de codes = UM, ou *OPTw, ou *HOS, ou ** pour tout
                  exemple de codes = UM,ou \*OPTw, ou '* HOS', ou '**' pour tout
           trouve le langage ( .ASM .BAS .C .FOR .PAS .PRO )
           trouve le langage ( .s .S .c .h .i .f .F .r .p .sh .csh )
       -A décode uniquement les commentaires de style Assembleur
       -B        style Basic
       -C        style C: C, c++, php ...
       -F        style Fortran
       -P        style Pascal
       -S        style Shell
       -a ajoute au fichier cible
       -f:
       -j précise que le fichier source est un fichier de projet.
       -l et -p:   ligne;  (compil.: %c ou %c en première colonne ou %c dans la ligne)
       -n insère un numéro de ligne
       -s copie dans le fichier cible et à l'écran
       -t ne copie que le commentaire
       -v mode bavard
       -w écrase le fichier cible (par défaut cette option est invalidée)
     ou: mkd ? .Voir aussi mkd.doc ou le manuel.     ou: mkd \? .Voir aussi le manuel: 'man mkd'  (5 caractères au maximum)
  --> codes: tout caractère ASCII   --> options:
  --> chemin_source: fichier source (option -j: si le fichier source est un fichier de projet) 
  --> chemin_cible: chemin du fichier cible
  A ou B ou C ou...s'il vous plaît.
.Sortie 2
 %s
(fichier %s :) %s est protégé en écriture.
 .Sortie 1
 .Sortie 2
 ASSEMBLEUR
 Erreur de syntaxe dans la ligne de commande '\:'
.Sortie 2
 Erreur de syntaxe dans l'argument '\:'
.Sortie 2 
 BASIC
 C
 Erreur de fermeture '%s'
.Sortie 2
 Erreur de fermeture: '%s'
.Sortie 2
 Erreur de fermeture: '%s'
.Sortie 2 
 Erreur. Le language n'a pas été trouvé !.
 Erreur. Le langage n'a pas été trouvé !.
.Sortie 2
 Exemple: mkd -Cs *Snv fichier.c *.str
 Exemple: mkd -Csnv '*S' fichier.c \*.vérif_structure
 FORTRAN
 Force le décodage des commentaires dans le style  Options -a ou -w s'il vous plaît...  Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d
 PASCAL
 Chemin cible: le suffixe est indéterminé.
 Chemin cible: erreur de syntaxe à ou après '/'
.Sortie 2
 Chemin_cible: erreur de syntaxe à ou après '\'
.Sortie 2
 SHELL
 Erreur de syntaxe '*' dans le chemin_source.
.Sortie 2
 Erreur de syntaxe: (chemin_source : '%s') == (chemin_cible = '%s')
 Erreur de syntaxe: Trop d'options de 'Langage':
 Erreur de syntaxe dans le chemin_source: suffixe '.doc'
.Sortie 2
 fichier doc : '%s' 
 erreur option -a ou -w pas trouvé
 exepté le carctère espace:' '  (5 caractères max)
 fichier '%s' par trouvé en lecture
 fichier '%s' pas trouvé en lecture
.Sortie 2
 erreur d'ouverture du fichier '%s' pour ajouter
.Sortie 2
 erreur d'ouverture du fichier '%s' pour écraser
.Sortie 2
 mkd version PC, mise à jour %s, USAGE:
 mkd version UNIX, mise à jour %s, USAGE:
 fichier de projet '%s' pas trouvé
.Sortie 2
 fichier de projet : '%s' 
 syntaxe: mkd [-ABCFPSafjlnpstvw] codes chemin_source [chemin_cible]
 