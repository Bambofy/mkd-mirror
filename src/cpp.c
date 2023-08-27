/*P
FILE NAME: cpp.c for konsole cpp.cc for individual compilation in c++ or
           cpp.inc.cc to include file in sources files with gtkmm

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
Date: ../../1991 by JPL mkdoc 3.12 for PC and UNIX
Date: ../../1995 by JPL mkdoc 3.22 for RED-HAT on LINUX
Date: ../../2004 by JPL mkdoc 4.00 for LINUX ubuntu
Date: 11/02/2010 by JPL Update for MS Visual C10 beta 2. 
Date: ../../.... by JPL Transformation into independant function for mkdcpp.
Date: ../03/2012 by CLARA Update to UTF-8 format (C++)
Date: 02/05/2012 by CLARA Special adaptation for mkdcppw with gtkmm
Date: 10/03/2013 by JPL Rewrite in english (en) to facilitate the translations
Date: 30/04/2013 by GC  Rewrite to correct End Of File control
Date: 03/05/2013 by JPL Resolve the EOF problem if the last block is open.

*/
// Date: ../../.... by ... purpose of the modification ....

/*T
 FILE NAME: cpp.c for konsole cpp.cc for individual compilation in c++ or
           cpp.inc.cc to include file in sources files with gtkmm
 
    Directives de tests unitaires version alpha 2013:
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
    commentaire doit être remplacé par un caractère de fin de ligne.
 
    Le caractère de fin de fichier (EOF) NE DOIT JAMAIS APPARAÎTRE DANS LE
    TEXTE DU FICHIER CIBLE.
    Ceci provoquait un bug dans la version Alpha de l'application fenêtrée
    mkdcppw à l'étape du test d'intégration.

    Ajouté le 18 avril 2013:
    Vérifiez que l'extraction de tous les commentaires avec pour code de 
    décodage '**' soient copiés et que ceux-ci soient à la bonne place.
 
*/


/*D 
	function cpp_
 -----------------------------------------------------------------------------
 FILE NAME: cpp.c for konsole cpp.cc for individual compilation in c++ or
           cpp.inc.cc to include file in sources files with gtkmm
 FUNTION NAME:
  cpp_
 
 SYNOPSIS, SYNTAX: 
  #include "/usr/include/mkd/version.h" // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/cpp.h"     // or mkd.h
  int cpp_(FILE * pfdoc, FILE * pnfile);
  FILE * pfdoc: pointer of the target file opened by the calling function 
  FILE * pnfile: pointer of the source file opened by the calling function  In UNIX / LINUX 

 ACTION, DESCRIPTION:
  The cpp_ function reads the source file (pnfile) transmitted from the 
  calling function, and decodes the comments pre-encoded in lines or 
  blocks of style c++. and then writing this comments in a target file 
  (pfdoc).
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
    -s: Add the comment to the screen to use shell redirections > , >> , 
       or ||.
    -t: With the t option only the commented text is copied.
       Without the t option the entire line or block is copied.
       The t option permit to generate directly exploitable and publishable
       documents. 

  Remarks:
    if the decoded comment begins with the characters / and *, the  comment
       is copied until find the characters * and /, whatever included any 
       comment-line starting with "//".
    if the decoded comment begins with the characters "//", the line is
       copied until find the end-of-line or new-line 'NL' character or 
       end-of-file 'EOF'.
       This provisions facilitate the automatic generation of header files
       (file.h ; .hpp ; etc.) and documentation of functions.

 CONFORMING TO:
  POSIX, ANSI C, BSD, ISO/IEC 9899:2011; gcc, MS-Vc10; UTF-8.

 PORTABILITY, 
  LINUX-Debian-systems, LINUX-Red-Hat, UNIX, gcc.
  Microsoft Visual studio under Windows : x86(Win32) x64(Win32 and WIN64)

 RETURN VALUE:
  Return 0 in case of success in konsole version, nothing with gtkmm.

 COPYRIGHT:
  © EELL, Éditeurs Européens de Logiciels Libres, EUPL 2007
  Association À  but non lucratif selon l'Article 11 de la convention 
  européenne des droits de l'homme.
  Vous êtes libre de copier reproduire et distribuer l’application selon les
  termes de la Licence EUPL totalement compatible avec la licence GNU.

 
 AUTHORS:
  © Contact: http://edeulo.free.fr/contacts/formmail.php
  Designer: intial JP Louyot (JPL)
  Updates : JPL and Clara Jimenez
  Traducteurs: Clara

 RESSOURCES:
  gtkmm 3 to compile mkdcppw with cpp.cc
  gtkmm with mkdw future widowed version.

 NOTES:
  Update April 2013 the Coded comment begin also in 3rd colomn

 BUGS:
  See bugs reports http://edeulo.free.fr/phpBB3

 SEE ALSO MANUAL:
  Man(3) attached in English.
  Command line : man 3 cpp_
 
*/


/*H  
	// File: cpp.c
	extern int cpp_ (FILE * pfdoc, FILE * pnfile);
*/

#ifndef GTKMM 
         // if GTKMM is not defined then it is a Konsole version
         // when GTKMM is defined the file is included to the compilation
         // *pfdoc and *pnfile are open by the calling function

#include "version.h"
#include "cpp.h"
 
   int cpp_ (FILE* pfdoc, FILE* pnfile)
   { //S Function begin for Konsole version
      /* 
      The following statements are made in the calling function in
      windowed version, and then not "extern" in windowed version.
      n, s, t, and codes, are always defined in calling function.
      */
      extern unsigned char n,s,t;       //w Konsole version
      extern char codes[];              //w Konsole version
#else
   { //S Function begin for gtkmm
#endif
      unsigned int i,tab;
      unsigned num = 0;
      long ll,nl;
      int c1 = STX; /* STX : Start Text */
      int c2 = STX;
      int c3 = STX;
/*O   while next character is not End Of File */
      while ( c1 != EOF && c2 != EOF && c3 != EOF )
      { /*Sw1 Col 7 while !EOF */
         bool ligne = 0;
/*O      if it is the first char then  c1=LF */
         if (c1==STX) c1='\n'; // STX is defined in version.h
/*O      else c1 is the next char */
         else c1=getc(pnfile);
         if (c1==EOF) break;
/*O      if the char is New Line 
         -- then mark the followed position in memory (long int 'nl') */
         if(c1=='\n')
         { /*S NL */
            nl=ftell(pnfile);
            tab=0;
            num++;
         } /*S NL */
         else
         { /*S endif!NL */
/*O         if the char is '\t' tabulation, then tab++ */
            if (c1=='\t')tab++;
/*O         else if the char is '/' */
            else if(c1=='/')
/*O         then: */
            { /*S char = '/' */
               c2=getc(pnfile); //P is not necessary to break here
               c3=getc(pnfile);
/*O            if the char is followed by c2 = '*' or '/' and if options[0]=0 
               -- or if it is followed by user char 'code[]' */
               if( (c2=='*'||c2=='/') && 
                   ( !codes[0]||       // all comments
                     c3 == codes[0] ||
                     c3 == codes[1] ||
                     c3 == codes[2] ||
                     c3 == codes[3] ||
                     c3 == codes[4]
                   )
                 )
//O
/*O            then: treat the inline or block comment */
               { /*S Treat the inline or block comment */
/*O               if c2 = '/' set the Boolean 'ligne' to true (=1) */
                  if(c2=='/') ligne=1;
/*O               recognise the comment position */
                  //Pw appearance of codes in lines if codes[] flags are false
                  // if(!codes[0])ungetc(c3,pnfile); //Pw depends of codes[]
                  ll=ftell(pnfile);
/*O               if option n is true then insert the line number */
                  if(n)
                  { /*S*/
                     fprintf( pfdoc, "%5d ", num );
                     if(s) printf( "%5d ", num );
                  } /*S*/
/*O               if option t is not true, 
                  then: */
                  if(!t)
                  { /*S option t false */
/*O                  positioning at the beginning line */
                     fseek(pnfile,nl,0);
                     /*w or: fseek(pnfile,(nl-ftell(pnfile)),1); */
/*O                  copy the beginning line in the target file */
                     for(i=(int)(ll-nl);i>0;i--)
                     { /*S*/
                        c1=getc(pnfile); //P in this case c1 ≠ EOF
                        putc(c1,pfdoc);
                        if(s)putch(c1);
                     } /*S*/
                  } /*S option t false */
/*O               else: (option t) */
                  else
                  { /*S option t true */
/*O                  copy the tabulations as much as there is in the source file */
                     for(i=0;i<tab;i++) //w warning to copy tab first
                     { /*S*/
                        putc('\t',pfdoc);
                        if(s)putch('\t');
                     } /*S*/
/*O                  copy space up to comment */
                     for(i=(int)(ll-nl-tab);i>0;i--) //w warning to copy spaces after tabs
                     { /*S*/
                        putc(' ',pfdoc);
                        if(s)putch(' ');
                     } /*S*/
                  } /*S option t true and */
//O
/*O               if the line boolean 'ligne' is true (=1) */
                  if(ligne)
/*O               then: 
                  copy the inline comment to End Of Line (EOL) or (EOF) */
                  { /*S Copy the inline last comment */
                     while ( (c1=getc(pnfile)) != '\n' && c1 !=EOF)
                     { /*Sw2 Col 22 Copy the comment */
                        putc(c1,pfdoc);
                        if(s)putch(c1);
                     } /*Sw2 Col 22 Copy the comment */
                     if(c1==EOF) break; // exit from w1 while
                     ungetc(c1,pnfile); /* pour la recopie fin de ligne */
                  } /*S Copy the inline last comment */
/*O               else while does not find the char * followed by / : */
//O                    
/*O                  copy the comment */
                  else
                  { /*S else !(line) copy the comment to end of block */
                     while ( !(c1=='*' && c2=='/') && c1!=EOF && c2!=EOF )
                     { /*Sw3 Col 22 */
                        c1=getc(pnfile); // get next char in source buffer
/*O                     if next char (c2) is NL and the followed char is EOF 
                           then break the while w3
                           else rewind C2 in the source buffer */
                        if (c1 == 0x0A)
                        {
                           if ( (c2=getc(pnfile) ) == EOF) break;  //P break while w3
                           else ungetc(c2,pnfile); // rewind if it is not EOF
                        }
/*O                     if next char is '*' put c the char to stdout and target buffer */
                        if( c1 != '*' )
                        { /*S*/
/*www                           if(c1=='\n') fprintf(pfdoc, "%s", NL );*/ 
/*www                           /*P CR/LF under DOS */
/*www                           else */
                           putc(c1,pfdoc);
                           if(s)putch(c1);
/*O                       if option n is true and char c1=NL 
                          then: 
                             insert the line number following NL */
                           if( n && c1=='\n' )
                           { /*S*/
                              num++;
                              fprintf( pfdoc,"%5d ", num );
                              if(s) printf("%5d ", num );
                           } /*S*/
                        } /*S*/
/*O                     if next char (c1) is '*' getc and see next char (c2) */
                        if (c1=='*') //P c1='*' c2=?
                        { /*S c1=* c2=? */
                           c2=getc(pnfile);
/*O                       if c2 is '/' then rewind c2 and c1 */
                           if(c2=='/')
                           { /*S c2=/ */
                              ungetc(c2,pnfile); // to rewind the '/' from end of block
                              ungetc(c1,pnfile); // to rewind the '*' from end of block
                           } /*S c2=/ */
/*O                       else c1 = always '*' and c2 ≠ '/' 
                             rewind c2 in source buffer 
                             put c1 to target buffer and to stdout if n is true */
                           else /*P c1 = always '*' and c2 ≠ '/' */
                           { /*S not end of comment */
                              //T fprintf(pfdoc, "\nc1 = %c  c2 = %c\n", c1, c2); //T
                              ungetc(c2,pnfile); // to rewind the char in file buffer
                              putc(c1,pfdoc); // copy the '*' to target file
                              if(s)putch(c1); // copy the '*' to stdout (and go to get next char)
                           } /*S not end of comment */
                        } /*S c1=* c2=? */
                     } /*Sw3 Col 22 */
                     //T if (c1==EOF) break;
                  } /*S else !(line) copy the comment to end of block */
//O
#ifdef FULL_LINE
/*O              BEGIN FULL_LINE */
/*O              *** Compilation option to copy last of line to target file */
/*O              if t option is false, 
                 then: */
                  if(!t)
                  { /*S Option t false */
/*O                  Copy the comment to End Of Line or EOF */
//P                     -- including '\r' (CR/LF) under DOS */
                     while ( (c1=getc(pnfile)) != '\n' && c1!=EOF )
                     { /*Sw4 Col 22 */
                        putc(c1,pfdoc);
                        if(s)putch(c1);
                     } /*Sw4 Col 22 */
                  } /*S Option t false */
/*O               else (option t true) */
                  else
/*O              END FULL_LINE *** Compil. option  */
#endif
//O 
/*O               t is true by default if FULL_LINE is not denined at the 
                  compilation */
                  { /*S (t is true) */
/*O                  Go to EOL without copying, except the carriage return */
                     while ( (c1=getc(pnfile)) != '\n' && c1!=EOF )
                     { /*Sw5 Col 22 */
                        if (c1=='\r')
                        { /*S*/
                           putc( c1, pfdoc );
                           if(s) putch( c1 );
                        } /*S*/
                     } //*Sw5 Col 22 */
                     if (c1==EOF) break; //P exit from while w1
                  } /*S (t is true) */
/*P               and next, copy New Lines under this form: CR/LF under DOS */
//T                  fprintf(pfdoc, "%s", NL ); //P obsolete ?
//T                  if(s) puts("");
                  putc(c1,pfdoc);
                  if(s)putch(c1);
/*O               and backward to NL */
                  ungetc(c1,pnfile);                   
               } /*S Treat the inline or block comment */
/*O            else: (it is not a comment) */
               else
               { /*S Not a comment */
/*O               Back behind two characters */
                  ungetc(c3,pnfile);
                  ungetc(c2,pnfile);
               } /*S Not a comment */
            } /*S endif char = '/' */
         } /*S endif!NL */
      } /*Sw1 Col 7 while !EOF */
/*O   return of a character back to avoid the End Of File EOF ! */
/*w   verify in tests this « character back » with EOF and EOL at end of file */
      nl=ftell(pfdoc);
      nl--;
      fseek(pfdoc,nl,0);
 
#ifndef GTKMM
      return 0;
#else
      //return;
#endif
   } /*S End funtion cpp_ konsole, or windowed version with gtkmm */

