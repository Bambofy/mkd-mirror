/*P
NOM DU FICHIER: asm.c pour console

PROJET: mkd 
Générer la documentation pré-écrite dans les fichiers de sources multiples.
Cette commande n'est pas intégrée dans les distributions standards UNIX / LINUX

PROJET INITIAL: mkdoc 1989 pour MS-DOS et UNIX. Projet obsolète.

DOSSIER: extractdoc 04/12/2009

MODIFICATIONS:
Date: ../../1986 by JPL Initial programming for MSDOS and UNIX on SUN
Date: ../../1991 by JPL mkdoc 3.12 for PC and UNIX
....
Le: 10/01/2010 par Clara objet de la modification: contrôle de l'accentuation
               des commentaires en ISO-8859-1
Le: 10/03/2010 par JPL objet de la modification: simplification de l'entête
Le: 17/03/2012 par JPL objet de la modification: corrections au format UTF-8
Date: 28/04/2013 by GC Mise en conformité avec les nouvelles directives EELL
*/

// Date: ../../.... by ... purpose of the modification ....

/*T
 NOM DU FICHIER: asm.c pour console
 
    Directives de tests unitaires version alpha 2013:
    -------------------------------------------------
    Vérifiez les options n, s et t séparément:
    Vérifiez que la numérotation des lignes est correcte dans tous les cas de
    décodage de lignes. n, ns. nt, nst.
    Vérifiez que le texte reste à la bonne place dans tous les cas de décodage:
    avec ou sans numérotation des lignes, avec ou sans l'option texte seul.
    -- Vérifiez que les tabulations sont bien prises en charge dans tous les 
       cas, décodage en début des lignes, et 'dans' les lignes.
    -- Vérifiez de même pour les espaces.
    La fonction doit être éprouvée de telle sorte qu'un commentaire qui se 
    termine par le caractère de fin de fichier soit entièrement copié dans le
    fichier cible.
 
    Le caractère de fin de fichier (EOF) NE DOIT JAMAIS APPARAÎTRE DANS LE
    TEXTE DU FICHIER CIBLE.

    Ajouté le 18 avril 2013:
    Vérifiez que l'extraction de tous les commentaires avec pour code de 
    décodage '**' soient copiés et que ceux-ci soient à la bonne place.

*/

/*D
        fonction asm_
 -----------------------------------------------------------------------------
 NOM DU FICHIER: asm.c pour console, asm.cc pour intégration en c++
  ( Format texte UTF-8 )

 SYNTAXE, SYNOPSIS:
  #include "version.h"
  #include "asm.h"
  int asm_(FILE *pfdoc, FILE *pnfile);
  FILE *pfdoc: pointe sur le fichier cible ouvert (ou créé) par la fonction 
    appelante.
  FILE *pnfile: pointe sur le fichier source ouvert par la fonction appelante.

 ACTION, DESCRIPTION:
  La fonction asm_() lit le fichier écrit en assembleur et extrait les
    commentaires; de structure, d'organigramme, de documents destinés aux
    programmeurs, le fichier d'entête (.h) ou encore, de documents destinés à
    l'utilisateur final.
  On utilise habituellement les 'Codes' d'identification des commentaires à
    extraire suivants :
    ;D pour la documentation générale
    ;H pour générer le fichier d'entête (header, .h ou .hpp)
    ;O pour générer l'organigramme
    ;S pour le contrôle de la structure du programme
    ;T pour les points de tests
    ;U pour la documentation utilisateur
  On peut aussi extraire tous les commentaires avec pour 'Code' le double
    étoile entouré de simples cotes : '**'
  Description des 'Options' d'extraction:
    -n : pour ajouter le numéro de la ligne du commentaire.
    -s : pour ajouter le commentaire extrait à la sortie standard; l'écran.
    -t : pour n'extraire que le commentaire. (Par défaut, toute la ligne)

 CONFORME À, CONFORMING TO:
  POSIX, ANSI C, BSD, ISO/IEC 9899:2011; gcc, MS-Vc10; UTF-8.

 PORTABILITY:
  LINUX-Debian-systems, LINUX-Red-Hat, UNIX, gcc.
  Microsoft Visual studio under Windows : x86(Win32) x64(Win32 and WIN64)

 VALEUR RETOURNEE:
  Ne retourne rien

 DROIT DE COPIE:
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

 AUTEURS, AUTHORS:
  © Contact: http://edeulo.free.fr/contacts/formmail.php
  Designer: intial JP Louyot (JPL)
  Updates : JPL, Clara Jimenez, and GC
  Traducteurs: Clara

 RESSOURCES:
  (gtkmm with mkdw future widowed version.)

 NOTES:
  Mise à jour: 2013 Conforme aux nouvelles directives avec UTF-8.
  Correction du défaut de fin de fichier.
  Correction de l'extraction des commentaires dans la ligne, avec l'option -t

 BUGS:
  See bugs reports http://edeulo.free.fr/phpBB3

 SEE ALSO MANUAL:
  Man(3) attached in English.
  Command line : man 3 asm_

*/

/*H  
	// asm.c, asm.cpp:
	extern int asm_(FILE *pfdoc, FILE *pnfile);
*/


/* --------------------------------------------*/

#include "version.h"
#include "asm.h"
/*O asm_ */
     int asm_(FILE *pfdoc, FILE *pnfile)
     { /*S asm */
/*P     options bool à définir dans main() ou winmain() */
         extern unsigned char n,s,t;
         extern char codes[];
         unsigned int tab;
         unsigned num = 0;
         long ll,nl;
         int c1,c2,c3;

         c1 = c2 = c3 = STX; /* Start Text */

/*O     tant que pas fin de fichier source (c1, c2, c3 différents de EOF)*/
         while ( c1 != EOF && c2 != EOF && c3 != EOF )
         { /*S w1 tq !EOF */
/*O         si début de texte faire c1=LF */
             if (c1==STX) c1='\n';
/*O         sinon prendre pour c1 le char suivant */
             else c1=getc(pnfile);
/*O         si le char est NL repérer la position du fichier qui suit 'NL' */
             if(c1=='\n')
             { /*S reperage debut de ligne */
                 num++;
                 nl=ftell(pnfile);
                 tab=0;
             } /*S reperage debut de ligne */

/*P -- si le char c1 est NL -------------------------------------------------*/

/*O         si le catractère est NL: */
             if (c1=='\n')
             { /*S ; en colonne 1 */
                 c2 = getc(pnfile);
                 if (c2==EOF) break;
                 c3 = getc(pnfile);
                 if (c3==EOF) break;
/*O             si c1 est suivi par c2 = ';' et 
                    'Codes' NULL ( cad tous les commentaires à copier )
                    ou suivi par un des 5 charactères 'Codes' d'extraction */
                 if ( c2 == ';' && 
                        (
                            !codes[0]||
                            c3 == codes[0] ||
                            c3 == codes[1] ||
                            c3 == codes[2] ||
                            c3 == codes[3] ||
                            c3 == codes[4]
                        )
                    )
/*O             alors copier les caractères dans le fichier doc, 
                et si option s ajouter à la sortie standard */

/*P-- sinon si c1 = ';' est en première colonne -----------------------------*/

                 { /*S copier */
/*O                 si option n insérer le numéro de ligne 
                    et si option s l'ajouter à la sortie standard */
                     if(n)
                     { /*S n */
                         fprintf( pfdoc, "%5d ", num);
                         if(s) printf( "%5d ", num);
                     } /*S n */
/*O                 si l'option t texte seul n'est pas validée */
                     if(!t)
                     { /*S !t */
/*O                     copier le début de ligne */
                         putc(c2,pfdoc); // ;
                         putc(c3,pfdoc); // caractère de d'extraction
/*O                     si option s copier aussi les 2 caractères à la sortie std */
                         if(s)
                         { /*S si opt s */
                             putch(c2);
                             putch(c3);
                         } /*S si opt s */
                     } /*S !t */
/*w                 sinon, option t vraie et copier tous les caractères
                        reculer de 1 caractère */
                     //w else if(!codes[0])ungetc(c3,pnfile);
/*O                 sinon, option t, remplacer les deux premiers caractères par 2 espaces */
                     if(t)
                     { /*S t true */
                         putc (' ',pfdoc);
                         putc (' ',pfdoc);
                         if(s)
                         { /*S s true */
                             putch(' ');
                             putch(' ');
                         } /*S s true */
                     } /*S t true */
/*O                 tant que l'on a pas trouvé le caractère fin de ligne NL ('\n')*/
                     while ( (c1 = getc(pnfile)) != '\n' && c1 != EOF)
                     { /*S w2 copy line */
/*O                     copier les caractères de la ligne */
                         putc (c1,pfdoc);
                         if(s) putch(c1);
                     } /*S w2 copy line */
                     if (c1==EOF) break; // du while w1
/*O                 copier aussi le caractère c1=NL, 
                    et avec l'option s envoyer le NL au terminal */
                     putc (c1,pfdoc);
                     if(s) putch(c1);
/*O                 revenir sur LF du fichier source */
                     ungetc(c1,pnfile);
                 } /*S copier */
/*O             sinon restituer les deux derniers caractères */
                 else
                 { /*S sinon pas début de commentaire en 1ère colonne */
                     ungetc(c3,pnfile);
                     ungetc(c2,pnfile);
                 } /*S sinon pas début de commentaire en 1ère colonne */
             } /*S ; en colonne 1 */

/*P--------- sinon si c1 = ';' est dans la ligne ----------------------------*/
             else
             { /*S else */
/*P             si c1 est tabulation incrémenter tab */
//P                 if (c1=='\t')tab++;
/*P             sinon si c1 = ; */
//P                 else 
                if (c1==';')
/*O             alors: */
                 { /*S char = ; */
                     c2=getc(pnfile);
/*O                 si codes[0]=0 ( tous les commentaires )
                       ou si suivi par c2 = 'Code' to extract the comment */
                     if(      !codes[0] ||
                         c2 == codes[0] ||
                         c2 == codes[1] ||
                         c2 == codes[2] ||
                         c2 == codes[3] ||
                         c2 == codes[4]
                       )
/*O                 alors: */
                     { /*S comment inline */
/*O                     repérer la position de début de commentaire, le ; */
                         //w if(!codes[0])ungetc(c2,pnfile); (tous les commentaires)
                         ll=ftell(pnfile); // retour avec repérage sur ;
/*O                     si l'option booléenne t est fausse (pas de texte seul) */
                         if(!t)
                         { /*S !t */
/*O                         se positionner en début de ligne */
/*T                         fseek ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
                             fseek(pnfile,nl,0); 
/*O                         si l'option n est vraie, insérer le numéro de ligne */
                             if(n)
                             { /*S n (numéro de ligne) */
                                 fprintf( pfdoc, "%5d ", num);
/*O                             si option s vraie, ajouter le numéro de ligne à l'écran */
                                 if(s) printf( "%5d ", num); // screen
                             } /*S n */
/*O                         copier toute la ligne tq pas NL LF, dans le fichier doc */
                             while ( (c1=getc(pnfile)) != '\n' && c1!=EOF)
                             { /*S w3 */
                                 putc(c1,pfdoc);
                                 if(s)putch(c1);
                             } /*S w3 */
/*O                         en cas de fin de fichier arrêter la boucle while w1 */
                             if (c1==EOF) break;
                         } /*S !t */
/*O                     si option t */
                         if (t)
                         { /*S option t */
/*O                         se positionner en dédut de ligne */
/*T                         fseek ou: fseek(pnfile,(nl-ftell(pnfile)),1); */
                             fseek(pnfile,nl,0);
/*O                         si option n vraie, insérer le numéro de ligne */
                             if(n)
                             { /*S n (numero de ligne) */
                                 fprintf( pfdoc, "%5d ", num);
/*O                             si s ajouter le numéro de ligne à l'écran */
                                 if(s) printf( "%5d ", num); // screen
                             } /*S n */
//P                         copier autant de tabulations qu'il y en a dans le source */
//P for(i=0;i<tab;i++)
//P { /*S tabs */
//P 	putc('\t',pfdoc);
//P 	if(s)putch('\t');
//P } /*S tabs */
/*O                         copier toute la ligne jusqu'à la position commentaire */
                             while ( (c1=getc(pnfile)) != ';' && c1!=EOF)
                             { /*S w */
                                 putc(' ',pfdoc);
                                 if(s)putch(' ');
                             } /*S w*/
                             if (c1==EOF) break; // w1
/*O                         ajouter un espace pour remplacer le caractère ';' */
                            // for(i=(int)(ll-nl-tab);i>0;i--)
                             { /*S espaces */
                                 putc(' ',pfdoc);
                                 if(s)putch(' ');
                                 c1=getc(pnfile);             // command 'Code' true
                                 if(c1!=' ')
                                 { /*S if 'Code' is true */
                                     putc(' ',pfdoc); // replace Code with space
                                     if(s)putch(' ');
                                 } /*S if 'Code' is true */
                             } /*S espaces */
/*O                         puis copier le commentaire tant que NL n'est pas trouvé */
                             while ( (c1=getc(pnfile)) != '\n' && c1!=EOF)
                             { /*S copier commentaire */
                                 putc(c1,pfdoc);
                                 if(s)putch(c1);
                             } /*S copier commentaire */
                             if(c1==EOF)break; // w1
                         } /*S option t */
                         putc('\n',pfdoc);if(s)putch('\n');   /*O copier NL */
                         ungetc(c1,pnfile);                   /*O revenir sur NL */
                     } /*S comment inline */
/*O                 sinon: */
                     else
                     { /*S*/
/*O                     renenir un caractère en arrière */
                         ungetc(c2,pnfile);
                     } /*S*/
                 } /*S char = ; */
             } /*S else */
         } /*S tq !EOF */
         return 0;
     } /*S asm */
