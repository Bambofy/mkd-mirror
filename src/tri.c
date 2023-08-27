
/*P
FILE NAME: tri.c for konsole tri.cc for individual compilation in
  c++ or tri.inc.cc to include file in sources files with gtkmm

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
Date: 09/06/1989 by JPL Update mkdoc 3.09
Date: 09/01/1991 by JPL mkdoc 3.11 for PC and UNIX
Date: 10/05/2013 by GC Update for mkd 2013

*/
// Date: ../../.... by ... purpose of the modification ....

/*T
 FILE NAME: tri.c for konsole tri.cc for individual compilation in
  c++ or tri.inc.cc to include file in sources files with gtkmm

 
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
	function tri_
 -----------------------------------------------------------------------------
 FILE NAME: tri.c for konsole tri.cc for individual compilation in
  c++ or tri.inc.cc to include file in sources files with gtkmm

 FUNTION NAME:
  tri_
 
 SYNOPSIS, SYNTAX: 
  #include "/usr/include/mkd/version.h" // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/tri.h"     // or mkd.h
  int tri_(FILE * pfdoc, FILE * pnfile);
  FILE * pfdoc: pointer of the target stream opened by the calling function 
  FILE * pnfile: pointer of the source stream opened by the calling function

 ACTION, DESCRIPTION:
  The tri_ function reads the source file (pnfile) transmitted from the 
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

  Remarks: (1991)
  Cette fonction de mkdoc permet le tri des commentaires en fonction des para-
  mètres CD1 CD2 CD3 CD4 CD5 compiles.
  avec l'option l (copie de ligne):
  CD1 et CD2 sont des caractères début de commentaires a placer en début de
  ligne comme en FORTRAN: c ou C ou * .
  CD3 est un caractère début de commentaire que l'on peut placer en tout point
  d'une ligne comme ; en assembleur, # en shell ou % en PostScript.
  Cette fonction permet des tris différents de SHELL_.C vu qu'elle ignore si
  # est dans une chaîne ou si elle est précédée du char \ .
  avec l'option p (copie de page ):
  CD4 est le caractère de début du commentaire et CD5 est la fin du commentaire
  comme en PASCAL : CD4={ et CD5=} . CD4=CD5=" peut a la rigueur permettre
  d'extraire des chaînes de caractères afin d’éditer un dictionnaire syntaxique
  toutefois " étant a la fois début et fin de caractère le résultat n'est pas
  assuré.

    
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
  Command line : man 3 tri_
 
*/

/*H  
	// File: tri.c
	void tri_ (FILE * pfdoc, FILE * pnfile);
*/

#include "version.h"
#include "tri.h"

void tri_(FILE * pfdoc, FILE * pnfile)
// FILE *pfdoc, *pnfile;
     { /*S tri */
        extern unsigned char l,p,n,s,t;
        extern char codes[];
        unsigned int i,tabl,tabp;
        unsigned int num;
        long lc,ll,nl;
        register int c1;
        int c2,c3;

        num = 0;
        c1 = c2 = c3 = STX; /* Start Text */

/*O    tant que pas fin de fichier source */
        while ( c1 != EOF && c2 != EOF && c3 != EOF )
        { /*S tq !EOF */
/*O       si début de texte faire c1=LF */
           if (c1==STX) c1='\n';
/*O       sinon prendre pour c1 le caractère suivant */
           else c1=getc(pnfile);
/*O       si le char est NL reperer la position suivant NL dans nl */
           if(c1=='\n')
           { /*S*/
           num++;
           nl=ftell(pnfile);
           tabl=tabp=0;
           } /*S*/

/*O###### si option ligne ###################################################*/
           if  (l)
           { /*S cas lignes */

/*O--------- si le caractère est NL -----------------------------------------*/

              if (c1=='\n')
              { /*S colonne 1 */
/*O             suivi par c2 = CD1 ou CD2 ou CD3
                et si codes[0]=0 ou si suivi par un des 5 codes d'extraction */
                 c2 = getc(pnfile);
                 if (c2==EOF) {ungetc(c2,pnfile);break;}
                 c3 = getc(pnfile);
                 if (c3==EOF) {ungetc(c3,pnfile);break;}
                 if( (c2 == CD1 ||
                      c2 == CD2 ||
                      c2 == CD3
                     )
                     &&
                     (!codes[0]||
                      c3 == codes[0] ||
                      c3 == codes[1] ||
                      c3 == codes[2] ||
                      c3 == codes[3] ||
                      c3 == codes[4]
                     )
                   )
/*O             alors copier les caractères dans le fichier cible,
                   et si option s vraie copier à la sortie standard. */
                 { /*S copier la ligne */
/* O                si il n'y a pas de code revenir un caractère en arrière */
//                    if (!codes[0]) ungetc(c3,pnfile);
/*O                si option n insérer le numéro de ligne  */
                    if(n)
                    { /*S*/
                       fprintf( pfdoc ,"%5d ", num );
                       if(s) printf( "%5d ", num );
                    } /*S*/
/*O                si pas option t */
                    if(!t)
                    { /*S !t */
/*O                   copier le début de ligne */
                       putc (c2,pfdoc); // c1 = LF
                       putc(c3,pfdoc);
                       if(s)
                       { /*S si opt s */
                          putch(c2);putch(c3);
                       } /*S si opt s */
                    } /*S !t */
/*O                sinon, option t vraie */                    
                    else
                    { /*S t */
/*O                   remplacer le début de ligne  par des espaces */
                       putc(' ',pfdoc); // remplace c2
                       if(s)putch(' ');
/*O                   si il n'y a pas de code revenir un caractère en arrière */
                       if (!codes[0]) ungetc(c3,pnfile);
/*O                   si non écrire un blanc à la place de c3 sans revenir */
                       else
                       { /*S cas c3 */
                          putc(' ',pfdoc);
                          if(s)putch(' ');
                       } /*S cas c3 */                   	
                    } /*S t */

/*O                tant que pas fin de ligne et pas EOF, copier la suite */
                    while ( (c1 = getc(pnfile)) != '\n' && c1 != EOF)
                    { /*S w copy line */
/*O                   copier la fin de la ligne */
                       putc (c1,pfdoc);if(s)putch(c1);
                    } /*S w copy line */
/*O                si le dernier caractère est EOF, quitter la boucle */
                    if(c1==EOF) break;
/*O                sinon, copier le LF (dernier caractère) */
                    putc (c1,pfdoc);
                    if(s) putch('\n');
/*O                revenir sur LF du fichier source */
                    ungetc(c1,pnfile);
                 } /*S*/
/*O             sinon retour des deux caractères c3 et c2 */
                 else
                 { /*S sinon pas à extraire */
                    ungetc(c3,pnfile);
                    ungetc(c2,pnfile);
                 } /*S sinon pas à extraire */
              } /*S colonne 1 */


/*O          sinon: traiter le commentaire dans la ligne */
              else
              { /*S else pas colonne 1 */
/*O---------    si c1 = 'CD3' (&  option ligne) --------------------------*/
                 if (c1==CD3)
                 { /*S char = CD3 */
/*O                si codes[0]=0 ou si suivi par c2 = char code utilisateur */
                    c2=getc(pnfile);
                    if (c2==EOF) {ungetc(c2,pnfile);break;}
                    if(!codes[0]||
                       c2 == codes[0] ||
                       c2 == codes[1] ||
                       c2 == codes[2] ||
                       c2 == codes[3] ||
                       c2 == codes[4]
                       )
/*O                alors: extraire le commentaire */
                    { /*S commentaire */
/*O                   repérer la position commentaire */
                       if(!codes[0])ungetc(c2,pnfile);
                       ll=ftell(pnfile);
/*O                   si option n insérer le numéro de ligne */
                       if(n) // depuis le dernier LF on n'a encore rien copié
                       { /*S*/
                          fprintf( pfdoc, "%5d ", num );
                          if(s) printf( "%5d ", num );
                       } /*S*/
/*O                   si pas option t */
                       if(!t)
                       { /*S*/
/*O                      se positionner en dédut de ligne */
                          fseek(pnfile,nl,0);
                          /*w ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
/*O                      copier dans le fichier cible toute la ligne tq pas NL (LF) */
                          while ( (c1=getc(pnfile)) != '\n' && c1 != EOF)
                          { /*S*/
                             putc(c1,pfdoc);
                             if(s)putch(c1);
                          } /*S*/
                          if (c1==EOF) break;
                       } /*S*/
/*O                   sinon: (option t) */
                       else
                       { /*S*/
/*O                      se positionner en dédut de ligne */
                          fseek(pnfile,nl,0);
/*O                      copier le début de ligne avec des tabulations et des espaces */
                          for(lc=nl;lc<ll;lc++)
                          { /*S first */
                             c1=getc(pnfile);
                             if (c1==EOF) break;
                             if (c1=='\t') 
                             {
                                putc('\t',pfdoc); // tab to target
                                if(s)putch('\t');      // tab to stdout
                             }
                             else 
                            {
                                putc(' ',pfdoc); // blank to target
                                if(s)putch(' ');      // blank to stdout
                             }
                          } /*S first */

/*O                      puis copier le commentaire tq pas NL et pas EOF */
                          while ( (c1=getc(pnfile)) != '\n' && c1!=EOF )
                          { /*S*/
                             putc(c1,pfdoc);
                             if(s)putch(c1);
                          } /*S*/
                          if (c1==EOF) break;
                       } /*S*/
                       putc('\n',pfdoc);if(s)putch('\n');   /*O copier NL */
                       ungetc(c1,pnfile);                   /*O revenir sur NL */
                    } /*S commentaire */
/*O                sinon: */
                    else
                    { /*S*/
                    ungetc(c2,pnfile);
                    } /*S*/
                 } /*S char = CD3 */
/*O             sinon si c1='\t' inc tabl */
                 else if(c1=='\t')tabl++;
              } /*S else pas colonne 1 */
           } /*S cas lignes */

/*O###### si option page ####################################################*/

           if (p)
           { /*S cas page */
/*O          si le char est identique a CD4 */
              if(c1==CD4)
              { /*S char = CD4 */
                 c2=getc(pnfile);
/*O             si codes[0]=0 ou si c1 est suivi par c2 'Codes' */
                 if(!codes[0]||
                    c2 == codes[0] ||
                    c2 == codes[1] ||
                    c2 == codes[2] ||
                    c2 == codes[3] ||
                    c2 == codes[4]
                   )
/*O             alors: */
                 { /*S traiter le commentaire */
/*O                repérer la position commentaire */
                    if(!codes[0]) ungetc(c2,pnfile);
                    ll=ftell(pnfile);
/*O                si option n insérer le numéro de ligne */
                    if(n)
                    { /*S*/
                       fprintf(pfdoc, "%5d ", num );
                       if(s) printf("%5d ", num );
                    } /*S*/
/*O                si pas option t */
                    if(!t)
                    { /*S!t*/
/*O                   se positionner en dédut de ligne */
                       fseek(pnfile,nl,0);
                       /*w ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
/*O                   copier la ligne jusqu'au commentaire, dans le fichier cible */
                       for(i=(int)(ll-nl);i>0;--i)
                       { /*S*/
                          c1=getc(pnfile);
                          putc(c1,pfdoc);
                          if(s)putch(c1);
                       } /*S*/
                    } /*S!t*/
/*O                sinon: (option t) */
                    if(t)
                    { /*S t */
/*O                   se positionner en dédut de ligne */
                       fseek(pnfile,nl,0);
/*O                   copier le début de ligne avec des tabulations et des espaces */
                       for(lc=nl;lc<ll;lc++)
                       { /*S first */
                          c1=getc(pnfile);
                          if (c1==EOF) break;
                          if (c1=='\t') 
                          {
                             putc('\t',pfdoc); // tab to target
                             if(s)putch('\t');      // tab to stdout
                          }
                          else 
                          {
                             putc(' ',pfdoc); // blank to target
                             if(s)putch(' ');      // blank to stdout
                          }
                       } /*S first */
                    } /*S t */
/*O                puis tq ne rencontre pas le char CD5, copier le commentaire */
                    while ( (c1=getc(pnfile)) != CD5 && c1 != EOF)
                    { /*S*/
                       putc(c1,pfdoc);
                       if(s)putch(c1);
/*O                   si option n et NL incrémenter et ajouter le numéro de ligne */
                       if(n && c1=='\n')
                       { /*S*/
                          num++;
                          fprintf(pfdoc, "%5d ", num );
                          if(s) printf( "%5d ", num );
                       } /*S*/
                    } /*S*/
                    if (c1==EOF) break;

#ifdef FULL_LINE     /*O *** FULL_LINE *** */
/*O                si pas option t */
                    if(!t)
                    { /*S*/
/*O                   copier les caractères jusqu'en fin de ligne */
                       ungetc(c1,pnfile);
                       while ( (c1=getc(pnfile)) != '\n' && c1!=EOF)
                       { /*S*/
                          putc(c1,pfdoc);
                          if(s)putch(c1);
                       } /*S*/
                    } /*S*/
/*O                sinon (option t) */
                    else
#endif               /*O *** END FULL_LINE *** */
                    { /*S*/
/*O                   aller au bout de la ligne sans copier sauf les '\r' */
                       while ( (c1=getc(pnfile)) != '\n' && c1!=EOF )
                          if (c1=='\r')
                          { /*S*/
                             putc( c1, pfdoc );
                             if(s) putch( c1);
                          } /*S*/
                    } /*S*/
                    if(c1==EOF) break;
                    putc('\n',pfdoc);if(s)putch('\n');   /*O copier NL */
                    ungetc(c1,pnfile);                   /*O revenir sur NL */
                 } /*S traiter le commentaire */

/*O             sinon: */
                 else
                 { /*S pas le cas */
                    ungetc(c2,pnfile);
                 } /*S pas le cas*/
              } /*S char = CD4 */
/* O          sinon si c1='\t' inc tabp */
//              else if(c1=='\t')tabp++;
           } /*S cas page */
        } /*S tq !EOF */
     } /*S tri */
