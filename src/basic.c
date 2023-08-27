
/*P
FILE NAME: basic.c for konsole basic.cc for individual compilation in
  c++ or basic.inc.cc to include file in sources files with gtkmm

PROJECT: mkd 
mkd is a UNIX command to extract pre-encoded comments lines to generate the 
software documentation according to ISO standards. 
mkd is the abbreviation of make documentation. This command was originally 
known under the name mkdoc (make documentation).
This command is not integrated into the standard distributions of Unix / Linux

INITIAL PROJECT: 
mkdoc 1989 for MS-DOS and UNIX now obsolete. CEM - University of Montpellier II

ADMINISTRATIVE RECORD: 
extractdoc 04/12/2009

FILE UPDATE:
Date: ../../1986 by JPL Initial programming for MSDOS and UNIX on SUN
Date: 09/02/1989 by JPL mkdoc ?? for PC and UNIX
Date: 12/02/1991 by JPL mkdoc 3.12 for PC and UNIX
Date: 04/05/2013 by Clara Update for UTF-8

*/
// Date: ../../.... by ... purpose of the modification ....

/*T
 FILE NAME: basic.c for konsole basic.cc for individual compilation in
  c++ or basic.inc.cc to include file in sources files with gtkmm

 RECOMMANDED TESTS:
  Cette fonction doit décoder les commentaires style Basic. 
  Voir aussi NOTES et option -l dans version.h

  Colonne n+ |0|1|2|3|4|5|6|7|8|9|A|B|C|
             |'|O| |C|o|m|m|e|n|t| | | |To NL....| toutes versions
             |R|E|M|O| |C|o|m|m|e|n|t| |To NL....| toutes versions
             |R|e|m| |O| |C|o|m|m|e|n|t|To NL....| depuis version 2013
  Notez que le 'Code' peut être placé en 3ème ou 4ème colonne avec REM.

 
    Directives de tests unitaires version alpha 2013
    Généralités pour tous les modules.
    -------------------------------------------------
    Vérifiez les options n, s et t séparément:
    Vérifiez que la numérotation des lignes est correcte dans tous les cas de
    décodage (lignes et blocs). n, ns. nt, nst.
    Vérifiez que le texte reste à la bonne place dans tous les cas de décodage:
    toute la ligne (dans la cas de la directive de compilation FULL_LINE), ou 
    texte seul.
    -- Vérifiez que les tabulations sont bien prises en charge dans tous les 
       cas, décodage des lignes et des blocs.
    -- Vérifiez de même pour les espaces.
    La fonction doit être éprouvé©e de telle sorte qu'un commentaire qui se 
    termine par le caractère de fin de fichier soit entièrement copié dans le
    fichier cible.
    Le caractère de fin de fichier décodé avant le(les) caractère(s) de fin de
    commentaire doit être remplacé par un caractère de fin de ligne 0x0A. Noter
    que le caractère 0x0A précédant EOF est considéré comme fin de ligne.
 
    Le caractère de fin de fichier (EOF 0xFF) NE DOIT JAMAIS APPARAÎTRE DANS LE
    TEXTE DU FICHIER CIBLE.
    Ceci provoquait un bug dans la version Alpha de l'application fenêtrée
    mkdbasicw à l'étape du test d'intégration.

    Vérifiez que l'extraction de tous les commentaires avec pour code de 
    décodage '**' soient copiés et que ceux-ci soient à la bonne place.
 
*/


/*D 
	function basic_
 -----------------------------------------------------------------------------
 FILE NAME: basic.c for konsole basic.cc for individual compilation in
  c++ or basic.inc.cc to include file in sources files with gtkmm

 FUNTION NAME:
  basic_
 
 SYNOPSIS, SYNTAX: 
  #include "/usr/include/mkd/version.h" // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/basic.h"   // or mkd.h
  int basic_(FILE * pfdoc, FILE * pnfile);
  FILE * pfdoc: pointer of the target stream opened by the calling function 
  FILE * pnfile: pointer of the source stream opened by the calling function

 ACTION, DESCRIPTION:
  The basic_ function reads the source file (pnfile) transmitted from the 
  calling function, and decodes the inline comments pre-encoded and writing
  this comments to a target file (pfdoc).
  Pre-coded characters are defined in a external global table 'Codes';

  The golbal variables are 'Codes' and 'Options'.
  The 'Codes': table of 5 characters: 
    extern char codes[]; 
    They must be dÃ©fined in the calling function:
    char codes[5] = {0,0,0,0,0};
  The 'Options': n,s,t,v:
    extern unsigned char n,s,t;
    They must be dEfined in the calling function:
    unsigned char n=0,s=0,t=0;
  With the options:
    -n: The transcript is preceded by line number. This allows to easily 
       reach the commented line.
    -s: Add the comment to the stdout to use shell redirections > , >> , 
       or ||.
    -t: With the t option only the commented text is extracted.
       Without the t option the entire line or block is copied.
       The t option permit to generate directly exploitable and publishable
       documents. 

  Remarks:
    
 CONFORMING TO:
  POSIX, ANSI C, BSD, ISO/IEC 9899:2011; gcc, MS-Vc10; UTF-8.

 PORTABILITY, 
  LINUX-Debian-systems, LINUX-Red-Hat, UNIX, gcc.
  Microsoft Visual studio under Windows : x86(Win32) x64(Win32 and WIN64)

 RETURN VALUE:
  Nothing.

 COPYRIGHT:
  © EELL, Éditeurs Européens de Logiciels Libres, EUPL 2007.
  Association à but non lucratif selon l'Article 11 de la convention
  européenne des droits de l'homme.
  Concédée sous licence EUPL, version 1.1 ou – dès leur approbation par la 
  Commission européenne - versions ultérieures de l’EUPL (la «Licence»).
  Vous ne pouvez utiliser la présente œuvre que conformément à la Licence.
  Vous pouvez obtenir une copie de la Licence à l’adresse suivante:
    http://ec.europa.eu/idabc/eupl5
  Sauf obligation légale ou contractuelle écrite, le logiciel distribué sous la
  Licence est distribué «en l’état», SANS GARANTIES OU CONDITIONS QUELLES
  QU’ELLES SOIENT, expresses ou implicites.
  Consultez la Licence pour les autorisations et les restrictions linguistiques
  spécifiques relevant de la Licence.
  La Licence est totalement compatible avec la licence GNU.

 AUTHORS:
  © Contact: http://edeulo.free.fr/contacts/formmail.php
  Designer: intial JP Louyot (JPL)
  Updates : JPL and Clara Jimenez
  Translations: Alizée, Clara, Luca, JPL, JPT, Martine

 RESSOURCES:
  gtkmm with mkdw future widowed version.

 NOTES:
  Update April 2013

 BUGS:
  See bugs reports http://edeulo.free.fr/phpBB3

 SEE ALSO MANUAL:
  Man(3) attached in English.
  Command line : man 3 basic_
 
*/

/*H  
	// File: basic.c
	void basic_ (FILE * pfdoc, FILE * pnfile);
*/

#include "version.h"
#include "basic.h"

void basic_(FILE * pfdoc, FILE * pnfile)
//O  FILE * pfdoc: pointer of the target stream opened by the calling function 
//O  FILE * pnfile: pointer of the source stream opened by the calling function
     { /*S basic */
        extern unsigned char n,s,t;
        extern char codes[];
        unsigned int num, tab, i;
        long ll,nl;
        register int c1;
        int c2,c3,c4,c5;

        num = 0;
        c1 = c2 = c3 = c4 = c5 = STX; /* Start Text */

/*O    tant que l'on n'est pas en fin de fichier source */
        while ( c1 != EOF && c2 != EOF && c3 != EOF && c4!=EOF && c5!=EOF)
        { /*S tq !EOF */

//O ----GET NEXT CHAR ---------------------------------------------------------

/*O       si debut de texte faire c1=LF */
           if (c1==STX) c1='\n';
/*O       sinon prendre pour c1 le char suivant */
           else 
           c1=getc(pnfile);
           if (c1==EOF) break;
/*O       si le char est NL reperer la position suivant NL dans nl */
           if(c1=='\n')
           { /*S*/
              num++;
              nl=ftell(pnfile);
           } /*S*/
/*O       sinon, le caractère n'est pas NL */

//O ----FIND IF NEXT CHAR BEGIN A COMMENT -------------------------------------

/*O       si le caractère suivant est '\'' ou les caractères ("REM") */
           if( c1=='\''|| //P c2, c3 ne sont lus que si c1 est faux
                (c1=='R'||c1=='r')&&
                ((c2=getc(pnfile))=='E' || c2 == 'e')&&
                ((c3=getc(pnfile))=='M' || c3 == 'm')
                )
/*O       alors c'est un commentaire à décoder */
           { /*S decoder */

//O ----YES IT HAS A COMMENT --------------------------------------------------

/*O          si on a REM vérifier si le caractère suivant est l'espace */
              if (c1!='\'')
              { /*S cas REM */
                 c4=getc(pnfile);
/*O             si le caractère suivant n'est pas l'espace reculer d'un caractère. */
                 if (c4!=' ') ungetc(c4,pnfile); //P unget c4 if not "REM_"
                 //T fprintf(pfdoc,"\nREM détecté \'%c%c%c%c\'\n",c1, c2, c3, c4);
              } /*S cas REM */
/*O          dans tous les cas de commentaires précédents: */
              { /*S test d'extraction */
                 c5=getc(pnfile); //P  c5 sera le char qui suit ', REM ou rem_
/*O             si il n'y a pas de 'Code' ou que le caractère suivant c5 
                est égal à un des 'Codes' de la ligne de commandes */
                 if( !codes[0] ||
                    c5 == codes[0] ||
                    c5 == codes[1] ||
                    c5 == codes[2] ||
                    c5 == codes[3] ||
                    c5 == codes[4]
                   )
/*O             extraire les commentaires */
                 { /*S extraire les commentaires */

//O ----YES THE COMMENT MUST BE EXTRACTED -------------------------------------
 
/*O                reperer la position du commentaire (après REM ou ') */
                    ll=ftell(pnfile);
/*O                dans tous les cas de commentaires à extraire */

/*O                se positionner en début de ligne */
                    fseek(pnfile,nl,0);
                    /*w ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
/*O                si option n insérer le numéro de ligne */
                    if(n)
                    { /*S*/
                       fprintf( pfdoc, "%5d ", num );
                       if(s) printf( "%5d ",num );
                    } /*S*/
/*O                copier la ligne jusqu'au commentaire, dans le fichier doc */
                    for(i=(int)(ll-nl);i>0;--i)
                    { /*S beginning line */

//O ----WRITE THE BEGGINNING OF LINE ------------------------------------------

                       c1=getc(pnfile);
                       if (c1==EOF) break;
                       if (t) // option t is true replace with spaces or tabs
                       {
                          if(c1=='\t') // tab
                          {
                             putc('\t',pfdoc); // tabulation
                             if(s) putch('\t');
                          }
                          else // not tab
                          {
                             putc(' ', pfdoc); // replace with space
                             if(s) putch(' ');
                          }
                       }
                       else // t not true: extract the full line
                       {
                          putc(c1,pfdoc);   // option t is not true
                          if (s) putch(c1);
                       }
                    } /*S beginning line */

//O ----EXTRACT THE END OF THE LINE -------------------------------------------

/*O                puis tq ne rencontre pas le char '\n', copier le commentaire */
                    while ( (c1=getc(pnfile)) != '\n' && c1!=EOF)
                    { /*S end of line */
                       putc(c1,pfdoc);
                       if(s)putch(c1);
                    } /*S end of line */
                    if (c1=='\n')
                    { /*S c1=NL */
                       putc('\n',pfdoc);
                       if(s)putch('\n');  //P copier NL
                       ungetc(c1,pnfile); //P revenir sur NL pour num++
                    } /*S c1=NL */
                    if (c1==EOF) break;
                 } /*S extraire les commentaires */

//O ----END OF EXTRACTED COMMENT ----------------------------------------------

/*O             sinon: (pas de commentaire à extraire) */
                 else
                 { /*S pas de commentaire à extraire */
                    ungetc(c5,pnfile); //P c5 est lu dans tous les cas de commentaires
/*O                si c1='R' renvoyer c3 et c2 */
                    if(c1=='R') // REM a échoué
                    {
                       if(c4==' ') ungetc(c4,pnfile); //w seulement si REM a été valide
                       // else c4=STX;
                       ungetc(c3,pnfile);
                       ungetc(c2,pnfile);
                    }
                 } /*S pas de commentaire à extraire */
              } /*S test d'extraction */
           } /*S decoder */
        } /*S tq !EOF */
     } /*S basic */
