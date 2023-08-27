/*P
FILE NAME: pascal.c for konsole pascal.cc for individual compilation in
  c++ or pascal.inc.cc to include file in sources files with gtkmm

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
Date: 09/06/1989 by JPL Update
Date: 30/12/1990 by JPL Udate for R3.11
Date: 09/01/1991 by JPL mkdoc 3.11 for PC and UNIX
Date: 12/02/1991 by JPL mkdoc 3.12 for PC and UNIX
...
Date: 06/05/2013 by Clara update for R 2013-05

*/
// Date: ../../.... by ... purpose of the modification ....

/*T
 FILE NAME: pascal.c for konsole pascal.cc for individual compilation in
  c++ or pascal.inc.cc to include file in sources files with gtkmm

 
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
    La fonction doit être éprouvée de telle sorte qu'un commentaire qui se 
    termine par le caractère de fin de fichier soit entièrement copié dans le
    fichier cible.
    Le caractère de fin de fichier décodé avant le(les) caractère(s) de fin de
    commentaire doit être remplacé par un caractère de fin de ligne 0x0A. Noter
    que le caractère 0x0A précédant EOF est considéré comme fin de ligne.
 
    Le caractère de fin de fichier (EOF 0xFF) NE DOIT JAMAIS APPARAÃTRE DANS LE
    TEXTE DU FICHIER CIBLE.
    Ceci provoquait un bug dans la version Alpha de l'application fenêtrée
    mkdbasicw à l'étape du test d'intégration.

    Vérifiez que l'extraction de tous les commentaires avec pour code de 
    décodage '**' soient copiés et que ceux-ci soient à la bonne place.
 
*/


/*D 
	function pascal_
 -----------------------------------------------------------------------------
 FILE NAME: pascal.c for konsole pascal.cc for individual compilation in
  c++ or pascal.inc.cc to include file in sources files with gtkmm

 FUNTION NAME:
  pascal_
 
 SYNOPSIS, SYNTAX: 
  #include "/usr/include/mkd/version.h"    // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/pascal.h"     // or mkd.h
  int pascal_(FILE * pfdoc, FILE * pnfile);
  FILE * pfdoc: pointer of the target stream opened by the calling function 
  FILE * pnfile: pointer of the source stream opened by the calling function

 ACTION, DESCRIPTION:
  The pascal_ function reads the source file (pnfile) transmitted from the 
  calling function, and decodes the comments pre-encoded in lines or 
  blocks. and then writing this comments to a target file (pfdoc).
  Pre-coded characters are defined in a external global table 'Codes';

  The golbal variables are 'Codes' and 'Options'.
  The 'Codes': table of 5 characters: 
    extern char codes[]; 
    They must be defined in the calling function:
    char codes[5] = {0,0,0,0,0};
  The 'Options': n,s,t,v:
    extern unsigned char n,s,t;
    They must be defined in the calling function:
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
  Command line : man 3 pascal_
 
*/

/*H  
	// File: pascal.c (Comments for UTF-8 text editor)
	void pascal_ (FILE * pfdoc, FILE * pnfile);
*/

#include "version.h"
#include "pascal.h"

void pascal_ (FILE * pfdoc, FILE * pnfile)
//O FILE * pfdoc: pointer of the target stream opened by the calling function 
//O FILE * pnfile: pointer of the source stream opened by the calling function
     { /*S pascal */
        extern unsigned char l,n,p,s,t; /*P rappels */
        extern char codes[];
        unsigned int i;
        unsigned num, curly; // curly brace = '{'
        long ll,nl;
        register int c1;
        int c2,c3;
/*O    initialisation des variables */
        num = 0;
        curly = 0;
        c1 = c2 = c3 = STX; /* Start Text */

/*O    tant que pas fin de fichier source */
        while ( c1 != EOF && c2 != EOF && c3 != EOF )
        { /*S tq !EOF */
//O ----GET NEXT CHAR ---------------------------------------------------------

/*O       si debut de texte faire c1=LF */
           if (c1==STX) c1='\n';
/*O       sinon prendre pour c1 le char suivant */
           else c1=getc(pnfile);
/*O       si le char est NL : */
           if (c1==EOF) break;
           if(c1=='\n')
           { /*S*/
/*O          incrémenter le numéro de ligne */
              num++;
/*O          repérer la position suivant NL dans nl et mettre nb tabulations à 0 */
              nl=ftell(pnfile);
           } /*S*/

//O ----FIND IF NEXT CHAR BEGIN A COMMENT -------------------------------------

/*O       si le char est '{' ou si le char est '(' suivi de '*' */
           if( c1=='{' || (c1=='(' && (c2=getc(pnfile))=='*') )
/*O       décoder le commentaire */
           { /*S char = début commentaire */
              c3=getc(pnfile);
/*O          si codes[0]=0 ou si le début de commentaire est suivi par 'Code' d'extraction */
              if(!codes[0]||
                 c3 == codes[0] ||
                 c3 == codes[1] ||
                 c3 == codes[2] ||
                 c3 == codes[3] ||
                 c3 == codes[4]
                )
/*O          alors, extraire le commentaire */
              { /*S traiter le commentaire */

//O ----YES THE COMMENT MUST BE EXTRACTED -------------------------------------

                 if ( c1== '{' ) curly = 1; 
                 else  curly = 0;
                 //T fprintf(pfdoc,"\ncurly = %d\n",curly); //T
/*O             repérer la position commentaire dans la ligne */
                 if(!codes[0]) ungetc(c3,pnfile);
                 ll=ftell(pnfile);

/*O             si option n insérer le numéro de ligne */
                 if(n)
                 { /*S*/
                    fprintf(pfdoc,"%5d ",num);
                    if(s)  printf("%5d ",num);
                 } /*S*/

/*O             se positionner en dédut de ligne */
                 fseek(pnfile,nl,0);
                 /*w ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
/*O             copier la ligne jusqu'au commentaire, dans le fichier doc */
                 for(i=(int)(ll-nl);i>0;--i)
                 { /*S beginning line */

//O ----WRITE THE BEGINNING OF LINE -------------------------------------------

                    c1=getc(pnfile);
                    if (c1==EOF) break;
                    if (t) // option t is true replace with spaces or tabs
                    { /*S t / */
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
                    } /*S t / */
                       else // t not true: extract the full line
                       {
                          putc(c1,pfdoc);   // option t is not true
                          if (s) putch(c1);
                       }
                 } /*S beginning line */

//O ----EXTRACT THE BLOCK -----------------------------------------------------

/*O             tq ne rencontre pas '}' si curly vrai, 
                ou '*' suivi de ')', copier le commentaire */
                //P C2 pas testé si curly vrai
                 while ( !(
                             ( (c1=getc(pnfile)) == '}' && curly )   ||
                             (c1=='*' && (c2=getc(pnfile)) == ')')
                          )
                       )
                 { /*S commentaire */
                    if (c1=='*') ungetc(c2,pnfile); //w vérifier avec la ligne 299
                    if (c1 == 0x0A)
                    {
                       c2=getc(pnfile);
                       if (c2 == EOF) break;
                       else ungetc(c2,pnfile); // rewind if it is not EOF
                    }
                    putc(c1,pfdoc);
                    if(s)putch(c1);
/*O                si option n et NL ajouter le numéro de ligne */
                    if(n && c1=='\n')
                    { /*S*/
                       num++;
                       fprintf(pfdoc,"%5d -",num);
                       if(s)  printf("%5d ",num);
                    } /*S*/
                 } /*S commentaire */

//O ----EXTRACT THE END OF THE LINE ifdef FULL_LINE ---------------------------

#ifdef FULL_LINE   /*O *** FULL_LINE *** */
/*O             si pas option t */
                 if(!t)
                 { /*S*/
/*O                copier les chars y compris code fin de comm. jusqu'en fin de ligne */
                    if(c1=='*') ungetc(c2,pnfile); //w vérifier avec la ligne 274
                    ungetc(c1,pnfile);
                    while ( (c1=getc(pnfile)) != '\n' && c1 != EOF )
                    { /*S*/
                       putc(c1,pfdoc);
                       if(s)putch(c1);
                    } /*S*/
                    if (c1 ==EOF) break;
                 } /*S*/
/*O             sinon (option t) */
                 else
#endif          /*O *** END FULL_LINE *** */

//O ----END OF EXTRACT THE END OF THE LINE ifdef FULL_LINE,GO TO NEXT CHAR ----

                 { /*S option t */
/*O                aller au bout de la ligne sans copier, sauf les 'retour chariot' */
                    while ( (c1=getc(pnfile)) != '\n' && c1 != EOF )
                    if( c1=='\r' )
                    { /*S*/
                       putc( c1, pfdoc );
                       if(s) putch( c1 );
                    } /*S*/
                    if ( c1==EOF) break; // case of EOF followed by NL
                 } /*S option t */

                 if (c1 == '\n')
                 { /*S NL */
                    putc(c1,pfdoc);    // copy NL to target file
                    if(s)puts("");     // copy NL (Cr/Lf stdout)                    
                    ungetc(c1,pnfile); // revenir sur NL
                 } /*S NL */
              } /*S traiter le commentaire */

//O ----NO THE COMMENT MUST BE NOT EXTRACTED ----------------------------------

/*O          sinon: */
              else
              { /*S pas le cas commentaire */
                 ungetc(c3,pnfile);
                 if (c1=='(') ungetc( c2, pnfile );
              } /*S pas le cas commentaire */
           } /*S char = début commentaire */
        } /*S tq !EOF */
     } /*S pascal */
