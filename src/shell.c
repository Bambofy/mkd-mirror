/*P
FILE NAME: shell.c for konsole shell.cc for individual compilation in
  c++ or shell.inc.cc to include file in sources files with gtkmm

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
Date: 09/06/1989 by JPL 
Date: 03/01/1991 by JPL mkdoc 3.11 for PC and UNIX
Date: ../../1991 by JPL mkdoc 3.12 for PC and UNIX
Date: 09/05/2013 by Clara for mkd 13.05 alpha
*/
// Date: ../../.... by ... purpose of the modification ....

/*T
 FILE NAME: shell.c for konsole shell.cc for individual compilation in
  c++ or shell.inc.cc to include file in sources files with gtkmm

 
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
 
    Le caractère de fin de fichier (EOF 0xFF) NE DOIT JAMAIS APPARAÎTRE DANS LE
    TEXTE DU FICHIER CIBLE.
    Ceci provoquait un bug dans la version Alpha de l'application fenêtrée
    mkdbasicw à l'étape du test d'intégration.

    Vérifiez que l'extraction de tous les commentaires avec pour code de 
    décodage '**' soient copiés et que ceux-ci soient à la bonne place.
 
*/


/*D 
	function shell_
 -----------------------------------------------------------------------------
 FILE NAME: shell.c for konsole shell.cc for individual compilation in
  c++ or shell.inc.cc to include file in sources files with gtkmm

 FUNTION NAME:
  shell_
 
 SYNOPSIS, SYNTAX: 
  #include "/usr/include/mkd/version.h" // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/shell.h"     // or mkd.h
  int shell_(FILE * pfdoc, FILE * pnfile);
  FILE * pfdoc: pointer of the target stream opened by the calling function 
  FILE * pnfile: pointer of the source stream opened by the calling function

 ACTION, DESCRIPTION:
  The shell_ function reads the source file (pnfile) transmitted from the 
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
   Ce programme copie les commentaires des lignes contenant le caractère # 
   suivi par un des caractères 'Codes' entrés en paramètre. Si le caractère
   '#' est précédé de \ ou si il est intégré dans une chaîne, alors il n'est
   pas considéré comme début de commentaire.

    
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
  Update May 2013

 BUGS:
  See bugs reports http://edeulo.free.fr/phpBB3

 SEE ALSO MANUAL:
  Man(3) attached in English.
  Command line : man 3 shell_
 
*/

/*H  
	// File: shell.c (Comments for UTF-8 text editor)
	void shell_ (FILE * pfdoc, FILE * pnfile);
*/

#include "version.h"
#include "shell.h"

void shell_ (FILE * pfdoc, FILE * pnfile)
//O  FILE * pfdoc: pointer of the target stream opened by the calling function 
//O  FILE * pnfile: pointer of the source stream opened by the calling function

     { /*S shell */
        extern unsigned char n,s,t;
        extern char codes[];
        unsigned int i,tab;
        unsigned int num;
        long ll,nl,lc;
        register int c1;
        int c2;

    num = 0;
    c1 = c2 = STX; /* Start Text */

/*O    tant que pas fin de fichier source */
        while ( c1 != EOF && c2 != EOF )
        { /*S tq !EOF */
/*O       si début de texte faire c1=LF */
           if (c1==STX) c1='\n';
/*O       sinon prendre pour c1 le char suivant */
           else c1=getc(pnfile);
           if (c1==EOF) break;
/*O       si le char est NL repérer la position qui suit 'NL' dans nl */
           if(c1=='\n')
           { /*S*/
             num++;
             nl=ftell(pnfile);
             tab=0;
           } /*S*/
           else
           { /*S !NL */

/*O          si le char est '\t' incrémenter tab */
              if (c1=='\t')tab++;

/*O          sinon si le char est '\"' */
              else if (c1=='\"')
/*O          alors aller jusqu'au prochain '\"' */
              { /*S string */
/*O             tant que le caractère suivant n'est pas " */
                 while ((c1=getc(pnfile))!='\"')
                 { /*S*/
/*O                si le char est EOF quitter la boucle */
                    if (c1==EOF)break;
                 } /*S*/
              } /*S string */
/*O          sinon si le char est bakslatch: */
              else if (c1=='\\')
/*O          alors: */
              { /*S*/
/*O             si le char suivant est # :  */
                 if((c1=getc(pnfile))=='#')
/*O             alors simuler un espace */
                 c1=' ';
/*O             sinon revenir en arrière */
                 else
                 { /*S*/
                    ungetc(c1,pnfile);
                    c1='\\';
                 } /*S*/
              } /*S*/
/*O          si le char est '#' */
              if (c1=='#')
/*O          alors: */
              { /*S char = # */
/*O             si codes[0]=0 (all chars) ou si suivi par c2 (char code utilisateur) */
                 c2=getc(pnfile);
                 if ( codes[0] == 0 ||
                     c2 == codes[0] ||
                     c2 == codes[1] ||
                     c2 == codes[2] ||
                     c2 == codes[3] ||
                     c2 == codes[4]
                    )
/*O             alors: */
                 { /*S comment*/
/*O                repérer la position commentaire */
                    //w ungetc(c2,pnfile);
                    ll=ftell(pnfile);
/*O                si option n insérer le numéro de ligne */
                    if(n)
                    { /*S*/
                       fprintf(pfdoc, "%5d ", num );
                       if(s) printf( "%5d ", num );
                    } /*S*/
/*O                se positionner en dédut de ligne */
                    fseek(pnfile,nl,0);
                    /*w ou: fseek(pnfile,(nl-ftell(pnfile)),1); */

/*O                si pas option t */
                    if(!t)
                    { /*S*/
/*O                   copier toute la ligne tq pas LF, dans le fichier doc */
                       while ( (c1=getc(pnfile)) != '\n' && c1 !=EOF)
                       { /*S*/
                          putc(c1,pfdoc);
                          if(s)putch(c1);
                       } /*S*/
                       if (c1==EOF) break;
                    } /*S*/

/*O                sinon: */
                    if(t) /*P option t */
                    { /*S t */
/*O                   copier le début de ligne avec des tabulations et des espaces */
                       for(lc=nl;lc<ll;lc++)
                       { /*S first */
                          c1=getc(pnfile);
                          if (c1==EOF) break;
                          //if(t)
                          { /*S t */
                             if (c1=='\t') 
                             {
                                putc('\t',pfdoc); // tab to target
                                if(s)putch('\t'); // tab to stdout
                             }
                             else 
                             {
                                putc(' ',pfdoc); // blank to target
                                if(s)putch(' '); // blank to stdout
                             }
                          } /*S t */
                       } /*S first */
/*O                   copier la suite du commentaire jusqu'à la nouvelle ligne */
                       while ( (c1=getc(pnfile)) != '\n' && c1!=EOF )
                       { /*S*/  
/*O                      copier le commentaire ( y compris '\r' sous DOS ) */
                          {
                             putc(c1,pfdoc);
                             if(s)putch(c1);
                          }
                       } /*S*/
                       if(c1==EOF) break;
                    } /*S*/
                    putc( c1, pfdoc);  // c1=NL
                    if(s) putch( c1 ); // copier NL */
                    ungetc(c1,pnfile); // revenir sur NL
                 } /*S comment */
/*O             sinon: */
                 else
                 {
                    ungetc(c2,pnfile);
                 }
              } /*S char = # */
           } /*S cas lignes */
         } /*S !NL */
      } /*S tq !EOF */

