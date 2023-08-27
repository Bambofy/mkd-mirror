/*P
FILE NAMES: fortran.c for konsole, or fortran.cc or fortran.inc.cc to include
            the file in windowed version of mkd with gtkmm
FUNCTION : fortran_()
 
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
Date: 17/04/2013 by Clara; Mise à jour vers UTF-8 et correction de fin de 
                    fichier pour version 2013 + introduction de la nouvelle
                    entête mkd* + numérotation des lignes.
Date: 21/04/2013 by JPL Nettoyage du code après les testsb unitaires.

*/
// Date: ../../.... by ... purpose of the modification ....

/*T
FILE NAMES: fortran.c for konsole, or fortran.cc or fortran.inc.cc to include
            the file in windowed version of mkd with gtkmm
FUNCTION : fortran_()
 
RECOMMANDED TESTS:
  Cette fonction doit décoder les commentaires style Fortran 77. 
  Pour le fortran 90 et ultérieurs Voir NOTES et option -l dans version.h

  Dès la version 2013 le caractère de décodage se place en 3 ème colonne
  Comme il est d'usage, ceci contrairement aux versions précédentes où
  le caractère de décodage se plaçait uniquement en 2 ème colonnes.
  Colonne |1|2|3|4|5|6|7|8|9|A|B|C|....To 72
          |C| |O| |C|o|m|m|e|n|t| |....| | | depuis version 2013
          |C|O| |C|o|m|m|e|n|t| | |....| | | toutes versions
          |C| |C|o|m|m|e|n|t| | | |....| | | toutes versions avec Codes '**'
  Notez que le 'Code' peut être placé en 2ème ou 3ème colonne.

TETS UNITAIRES:
  Veiller à ce que les commentaires restent à la bonne place quelle que soient
  les colonnes utilisées pour le décodage (2ème ou 3éme colonne) augmenté du 
  numéro de ligne.
  Vérifier dans cette nouvelle version, que le numéro de ligne s'écrit 
  correctement, sur 5 colonnes.
  Veiller à ce que le fichier cible ne contienne jamais le caractère de fin de
  fichier EOF.
  
  3 cas peuvent se présenter:
  Cas 1 : Codes est '**' tous les caractères doivent être copiés
  Cas 2 : colonne 2 identifie le commentaire de la ligne à copier
  cas 3 : Colonne 2 est un espace et colonne 3 identifie la ligne de commentaire
          à copier
  Vérifiez tous les cas avec les options n,s,t

  Testez de la même façon le fortran 90 avec l'option de compilation CD3 = '!'

*/

// Description de la fonction: (Utile pour le manuel man 3)
/*D
 NAME:
  Function: fortran_().
  Files: fortran.c for Kosole or fortran.cc or fortran.inc.cc for included
  file in windowed version with gtkmm

 SYNOPSIS:
  In UNIX / LINUX environment:
  #include "/usr/include/mkd/version.h" // IMPORTANT: Compilation directives
  #include "/usr/include/mkd/fortran.h" // or mkd.h
  In local environment:
  #include "version.h"
  void fortran_(FILE * pfdoc, FILE * pnfile);

 DESCRIPTION:
  Fortran 77: (ASCII)
  -------------------
  Originally Fortran programs were written in a fixed column format for the 
  cards. 
  A letter "C" in column 1 caused the entire card to be treated as a comment
  and ignored by the compiler.
  Usage:
  The comment character begin with the C or c or * in first colomn frequently
  followed by a space and shall not exceed the 72nd colomn for fortran 77.
  The mkd 'Code' character de must by placed in the 2nd or in 3rd colomn.
  
  The golbal variables are 'Codes' and 'Options'.
  The 'Codes': table of 5 characters:
      extern char codes[]; 
      They must be defined in the calling function:
      char codes[5] = {0,0,0,0,0};
  The 'Options': l,n,s,t. 
      see NOTES for inline ! comment
      extern unsigned char n,s,t;
      They must be defined in the calling function:
      unsigned char n=0,s=0,t=0;
  With the options:
   n: The transcript is preceded by line number on 5 colomns. This allows to 
      easily reach the commented line. (Warning with the tabs ...)
   s: Add the comment to the screen to use shell redirections > , >> , or ||.
   t: With the t option only the commented text is copied.
      Without the t option the entire line or block is copied.
      The t option permit to generate directly exploitable and publishable
      documents. 

 RETURN VALUE:
  Nothing

 CONFORMING TO: or STANDARDS: 
  POSIX, ANSI C, BSD, ISO/IEC 9899:2011; gcc, MS-Vc10; UTF-8.

 PORTABILITY:
  LINUX-Debian-systems, LINUX-Red-Hat, Windows NT, etc.

 COPYRIGHT:
  © Contact: http://edeulo.free.fr/contacts/formmail.php
  © EELL, Éditeurs Européens de Logiciels Libres, 2007
  Association à but non lucratif selon l'Article 11 de la convention européenne 
  des droits de l'homme.

 AUTHORS:
  Designer: intial JP Louyot (JPL)
  Updates : JPL and Clara Jimenez
  Traducteurs: Clara

 RESSOURCES:
  gtkmm with mkdw future widowed version.

 NOTES:
  Update April 2013 the Coded comment begin also in 3rd colomn

 BUGS:
  See bugs reports http://edeulo.free.fr/phpBB3

 SEE ALSO:
  Fortran 90:
  -----------
  Character ! is the inline comment starting with this character to NewLine.
  See -l compilation option #define CD3 '!' in version.h

  Fortran 2003:
  -------------
  The interface with the C languages are insured with the external module
  ISO_C_BINDING to facilitate access at the C libraries.

  mkd for fortran 90 with the -l option: Decode The inline comment '!' if the
  option CD3 are defined with the char '!' in version.h.
  Unix / Linux Man(3) attached in English. Command line : man 3 fortran_
 
*/

/*H  
	// File: fortran.c
	void fortran_ (FILE * pfdoc, FILE * pnfile);
*/


#ifndef GTKMM 
  // If GTKMM is not defined then it is a Konsole version
  // when GTKMM is defined the file is included to the compilation
  // *pfdoc and *pnfile are open by the calling function
#include "version.h"
#include "fortran.h"

void fortran_(FILE * pfdoc, FILE * pnfile)
    { /*S fortran */
        extern unsigned char n,s,t;
        extern char codes[];
#else
    { //S Function begin for gtkmm (with fortran.cc included file)
#endif
// #define TESTS
#ifdef TESTS
        int cas1 = 0; //T pour les tests
        int cas2 = 0; //T pour les tests
        int cas3 = 0; //T pour les tests
#endif
        int inbc = 0;      // nombre de caractères sur la pile
        unsigned num = 0; // Numéro de ligne
        unsigned i ;      // Compteur
        int copyflag = 0;  // drapeau commentaire à copier
        register int c0;  // entier dans le registre du processeur
        int c1,c2,c3;      // entiers en mémoire vive sur la pile
/*O    initialisation des valeurs sur la pile à NULL */
        c0 = c1 = c2 = c3 = 0; 

/*O    tant que l'on n'est pas en fin de fichier source */
        while ( c0 != EOF && c1 != EOF && c2 != EOF && c3 != EOF )
        { /*S tq !EOF */        
/*O        si début de texte faire c0 = retour chariot */
            if (!c0) c0='\n'; // ceci impose la première colonne
/*O        sinon copier dans le registre c0 le caractère suivant */
            else c0=getc(pnfile);
            if (c0 == EOF) break;

/*O------- si le char est NL le caractère suivant est en 1ère colonne ------*/
            if (c0=='\n') // précède la première colonne
            { /*S colonne 1 */
/*O            si suivi par c1 = 'C' ou 'c' ou '*' */
              /* et si codes[0]=0 ou si suivi par un espace et un des 5 char 
               code d'utilisateur */
                num++;
                copyflag = 0;
                c1 = getc(pnfile);
                if (c1 == EOF) break; // quitter si le caractère en 1 ère colonne est EOF 
                inbc = 1; // 1 caractère copié sur la pile (c1)
                if (c1 == 'C' || c1 == 'c' || c1 == '*')
                { /*O carte de commentaire */
/*O                si il n'y a pas de 'Code' à décrypter copier tous les commentaires */
                    if ( !codes[0] )
                    { /* Cas 1 copier tous les commentaires ('Code' NULL) */
#ifdef TESTS
    cas1++;
#endif
                        copyflag = 1;
                        if (n) fprintf( pfdoc,"%5d ", num );
/*O                    copier le début de ligne 1 ère colonne si t est invalide */
                        if (!t) putc (c1,pfdoc); // colonne 1
                        else putc (' ',pfdoc); // colonne 2
/*O                    si option s copier de même à la sortie standard */
                        if (s && n) printf("%5d ", num );
                        if (s && !t)putch(c1);
                        if (s && t)putch(' '); // colonne 2
                    } /* Cas 1 copier tous les commentaires ('Code' NULL) */

/*O                sinon, identifier les codes en 2ème ou 3ème colonne: */
                    else
                    { /*S commentaire ok cas 2 ou 3 (avec 'Code')*/
                        c2 = getc(pnfile);
                        if (c2 == EOF) break;
                        inbc=2; // 2 caractères copiés sur la pile (c1 + c2)
/*O                    si colonne 2 n'est pas un espace et qu'il y a des 'Codes', identifier */
                        if (c2 != ' ') 
                        { /*S cas 2 si colonne 2 n'est pas un espace */
#ifdef TESTS
    cas2++;
#endif

                            if (
                                c2 == codes[0] ||
                                c2 == codes[1] ||
                                c2 == codes[2] ||
                                c2 == codes[3] ||
                                c2 == codes[4]
                               )
                            copyflag = 1; // copyflag vrai si le code est identifié

                        } /*S cas 2 si colonne 2 n'est pas un espace */
/*O                    sinon si la 2ème colonne est un espace identifier la 3 ème colonne */
                        else if (c2 == ' ')
                        { /*S cas 3 colonne 2 est un espace */
#ifdef TESTS
    cas3++;
#endif

                            c3 = getc(pnfile);
                            if (c3 == EOF) break;
                            inbc = 3; // 3 caractères copiés sur la pile (c0 + c1 + c2)
                            if (
                                c3 == codes[0] ||
                                c3 == codes[1] ||
                                c3 == codes[2] ||
                                c3 == codes[3] ||
                                c3 == codes[4]
                               )
                            copyflag = 1; // copyflag vrai si colonne 3 identifiée 'Code'
                        } /*S cas 3 colonne 2 est un espace */
                    } /*S commentaire ok cas 2 ou 3 (avec 'Code')*/

/*O                si le texte est à copier dans le fichier cible: */
                    if (copyflag) // donc pas de EOF dans c0 c1 c2 c3 et 'Code' existe
/*O                alors copier les caractères dans le fichier doc, et si opt s copier à 
                   la sortie standard: */
                    { /*S copier */
/*O                    si pas option t et 'Code' présent */
                        if(!t && inbc > 1)
                        { /*S copier le début de la ligne */
/*O                        si n vrai copier le numéro de ligne sur 5 chiffres 
                           décimaux */
                            if (n) fprintf( pfdoc,"%5d ", num );
/*O                        copier le début de ligne */
                            putc (c1,pfdoc); // colonne 1
                            if (inbc > 1 ) putc(c2,pfdoc);   // Colonne 2 
                            if (inbc == 3) putc(c3,pfdoc);   // 3ème colonne
/*O                        si opt s copier aussi à la sortie standard */
                            if(s)
                            { /*S si opt s copier aussi à la sortie standard */
                                if (n) printf("%5d ", num );
                                putch(c1);
                                if (inbc > 1 ) putch(c2);
                                if (inbc == 3) putch(c3);
                            } /*S si opt s */
                        } /*S copier le début de la ligne */

/*O                    sinon, (option t) et 'Code présent */
                        else if (t && inbc > 1) //w (!codes[0]) // sinon si pas de 'Code'
                        { /*S espaces en début de ligne */
/*w                       si n est vrai, copier le numéro de ligne dans le fichier
                          cible et à la sortie standard */
                           if (n) fprintf( pfdoc,"%5d ", num ); // target file
                           if(s) printf("%5d ", num );          // stdout
/*O                       remplacer les premières colonne  par des espaces */
                           for (i=inbc ; i>0 ; i--) 
                           { /*S espaces */
                               putc(' ',pfdoc);
                               if(s)putch(' ');
                           } /*S espaces */
                        } /*S espaces en début de ligne */

/*O                    Dans tous les cas de commentaires la suite du commentaire est à copier */
/*O                    tant que pas fin de ligne et pas EOF (On ne soucie pas du
                       nombre de 72 colonnes) */
                        while ( ( c0=getc(pnfile) ) != '\n' && c0 != EOF )
                        { /*S while copy line */
/*O                        copier les chars de la ligne */
                            putc (c0,pfdoc);
                            if(s)putch(c0);
                        } /*S while copy line */

/*O                    si on est arrivé en fin de fichier avant NL */
                        if ( c0 == EOF )
                        { /* cas EOF */
/*O                        //w copier NL dans le fichier cible et à la sortie standard */
                           //w pas obligatoire car ajoute une ligne vide
                            //w putc ('\n',pfdoc); //w pas obligatoire
                            //w if(s) putch('\n'); //w pas obligatoire
/*O                        interrompre la boucle */
                            break;
                        } /* cas EOF */                   
/*O                    copier le dernier caractère (non EOF, donc NL) */
                        putc (c0,pfdoc);
                        if(s) putch('\n');
/*O                    revenir sur NL du fichier source  pour continuer la boucle en colonne 1 */
                        ungetc(c0,pnfile);
                    } /*S copier */
                } /*O carte de commentaire */

/*O            sinon ne pas copier dans le fichier doc et revenir sur les derniers
               caractères */
                else
                { /*S sinon, pas copier */
                    if (inbc-- == 3) ungetc(c3,pnfile); // 3 caractères copiés
                    if (inbc-- == 2) ungetc(c2,pnfile); // 2 caractères copiés
                    if (inbc-- == 1) ungetc(c1,pnfile); // C en 1ère colonne
                    ungetc(c1,pnfile); // cas NL en 1ère colonne
                } /*S sinon, pas copier */
            } /*S colonne 1 */
            inbc = 0 ; //w pas nécessaire si remis à 0 à la fin des blocs
        } /*S tq !EOF */
#ifdef TESTS
        fprintf( pfdoc, "\nCas 1 tous les commentaires: %5d ", cas1 );
        fprintf( pfdoc, "\nCas 2 colonne 2 sans espace: %5d ", cas2 );
        fprintf( pfdoc, "\nCas 3 colonne 2 avec espace: %5d \n", cas3 );
#endif
        return;
    } /*S fortran */

