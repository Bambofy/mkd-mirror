��    L      |  e   �      p     q     �     �     �     �  B   �  C     I   [  8   �  @   �  -        M     j     �     �     �     �  
   �  -   	  K   5	     �	      �	     �	     �	  0   �	  *   "
  *   M
     x
     �
     �
  C   �
     �
  "        8     G     _     h  
   q     |      �     �     �     �     �        "     1   A  #   s  /   �     �     �     �  4   	  5   >     t  %   |  1   �  1   �       )     ;   7  +   s  2   �     �      �          %  %   C  )   i  +   �  #   �  %   �  $   	     .  E   D  i  �     �          !     8     O  T   n  S   �  U     R   m  L   �  E        S  !   o     �     �     �     �  
     5     k   G      �  4   �  #   	      -  3   N  /   �  1   �     �     �       D        b  *   �     �     �     �     �  
   �  (     (   +     T     [  6   h  6   �  6   �  2     ;   @  $   |  2   �     �     �     �  5     6   H       $   �  ?   �  ?   �     ,  /   3  ;   c  .   �  8   �       *     )   I  *   s  9   �  =   �  1     &   H  '   o  /   �     �  =   �            
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
POT-Creation-Date: 2012-03-27 16:28+0200
PO-Revision-Date: 2013-03-30 10:23+0100
Last-Translator: Jean-Paul Louyot <jeanpaullouyot@free.fr>
Language-Team: German
Language: de
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=2; plural=(n != 1);
 

(Datei %s :)
 

Dokument %s abgeschlossen
 

Dokumentdatei: '%s'
 

Dokumentdatei: '%s'
 
 ÜBERSCHREIBEN '%s' ...  y?
                   Seite: (Kompilation Optionnen:  Beginnen mit %c und endet mit %c)
                  Beispiel-Codes = UM, oder *OPTw, oder '*HOS', oder '**' für alle
                  Beispiel Codes = UM, oder \*OPTw, oder '* HOS', oder '**' für alle
           sucht Programmiersprache ( .ASM .BAS .C .FOR .PAS .PRO ) Sprache finden
           sucht Programmiersprache  ( .s .S .c .h .i .f .F .r .p .sh .csh )
       -A Stil Assembler (Dekodiert nur Kommentare in Assembler Stil)
       -B        Stil Basic
       -C        Stil C, C++, php
       -F        Stil Fortran
       -P        Stil Pascal
       -S        Stil Shell
       -a fügt die Zieldatei
       -f:
       -j Benutzen Sie nur mit Quellen-Projekt-Datei.
       -l und -p;  Zeile: (Kompilation Optionen: von: %c oder %c in der ersten Spalte oder %c in der Zeile)
       -n Zeilennummer einfügen
       -s Kopiert in der Zieldatei und in Bildschirm
       -t kopiert nur den Kommentar
       -v Spricht viel (verbose)
       -w Überschreiben Zieldatei (Standardoption)
     oder: mkd ?. Siehe mkd.doc oder im Handbuch     oder:mkd \? .Siehe auch im Handbuch 'man mkd'  (5 Zeichen max)
  --> Codes: alle ASCII  --> Optionen:
  --> Quellpfad: Quelldatei (Option j: nur mit Quellen-Projekt-Datei
  --> Zieldateipfad: Zieldatei
  A or B oder C or...bitte.
.Return-code 2
 %s
(Datei %s :) %s ist schreibgeschützt.
 .Return-code 1
 .Return-code 2
 ASSEMBLER
 Arg. Syntax-Fehler '\:'
.Return-code 2 
 Arg. Syntax-Fehler '\:'
.Return-code 2 
 BASIC
 C, c++, php
 Fehler '%s' beim Schließen der Datei:
.Return-code 2
 Fehler beim Schließen der Datei: '%s'
.Return-code 2
 Fehler beim Schließen der Datei: '%s'
.Return-code 2
 Fehler, Programmiersprache ist nicht definiert !.
 Fehler, Programmiersprache nicht gefunden !.
.Retun-code 2
 Beispiel: mkd -Cs *Snv file.c *.str
 Beispiel: mkd -Csnv '*S' file.c \*.Audit-Struktur
 FORTRAN
 Ausgewählte Kommentarstil Option a oder w bitte...  Optionen a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d Optionen a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d
 PASCAL
 Zieldateipfad: Undefinierte Suffix.
 Zieldateipfad: Syntax-Fehler bei oder nach '/'
.Return-code 2 
 Zieldateipfad: Syntax-Fehler bei oder nach '\'
.Return-code 2 
 SHELL
 Syntax Fehler '*' in Quellpfad.
.Return-code 2
 Syntaxfehler: (Quellpfad : '%s') == (Zieldateipfad = '%s')
 Syntax-Fehler: Zu viele Optionen der Sprache:
 Syntax-Fehler: Quellpfad, Suffix '.doc'
.Return-code 2 
 Dokumentdatei : '%s' 
 Fehler : Option -a oder -w nicht gefunden
 Ausnahme der Zeichen: ' ' (5 ASCII max.)
 Datei '%s' nicht gefunden für Wiedergabe
 Datei '%s' nicht gefunden für Wiedergabe
.Return-code 2
 Eröffnung Datei '%s' Fehler für hinzufügen
.Return-code 2
 Eröffnung Datei '%s' Fehler für Überschreiben
 mkd PC-Version, Update %s, GEBRAUCH: 
 mkd UNIX Version, Update %s, GEBRAUCH:
 Projektdatei '%s' nicht gefunden.Return-code 2
 Projektdatei : '%s' 
 Syntax: mkd [-ABCFPSafjlnpstvw] Codes Quellpfad [Zieldatei] 
 