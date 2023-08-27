/*
* © mkd, version 2009.12 et ultérieures
*
* Concédée sous licence EUPL, version 1.1 ou – dès leur approbation par la
* Commission européenne - versions ultérieures de l’EUPL (la «Licence»).
* Vous ne pouvez utiliser la présente œuvre que conformément à la Licence.
* Vous pouvez obtenir une copie de la Licence à l’adresse suivante:
*
* http://ec.europa.eu/idabc/eupl5
*
* Sauf obligation légale ou contractuelle écrite, le logiciel distribué sous
* la Licence est distribué «en l’état»,
* SANS GARANTIES OU CONDITIONS QUELLES QU’ELLES SOIENT, expresses ou implicites.
* Consultez la Licence pour les autorisations et les restrictions linguistiques
* spécifiques relevant de la Licence.
*/

/*P
	NOM DU FICHIER: version.h
	PROJET INITIAL: mkd console linux & MSDOS
	DOSSIER INITIAL : mkdoc3.12 Centre d'Electronique de Montpellier
	PROGRAMMEUR: JPL 
	DATE: 18/12/2009
	MODIFICATIONS:
	le: 09/01/2011 par JPL objet: Ajouté l'option de compilation pour MSDEV41
	le: 10/01/2012 par JPL objet: Ajouté la définition std_C pour compilation UNIX STD
	le: 25/03/2012 par Clara objet: internationalisation
	le: 27/03/2012 par jpl objet: internationalisation en utf-8
	le: 10/04/2013 par Cardabela: Modification mineure. Alignement des commentaires.
        le: 11/05/2013 par jpl mise à jour des définitions CD* pour tri.c
*/
// 	le: ../../.. par .............. objet de la modification ....

/*E ?C?*/
/**# MKD.C ############################*/ /*H*/
/*U            UTILISATEURS            */ /*H*/
/*O            ORGANIGRAMME            */ /*H*/
/*S              STRUCTURE             */ /*H*/
/*T                TESTS               */ /*H*/
/*P             PROGRAMMEUR            */ /*H*/
/*www     remarques particulieres      */ /*H*/
/**####################################*/ /*H*/

// define VERSION line 173

#define UNIX 		/*O UNIX version */ /* Delete this line for PC version */
//#define GTKMM		/*O Version fenêtrée avec gtkmm pour mkdcppw uniquement */

#ifndef UNIX            /*H*/
#define PC              /*O version de compilation PC   */  /*H*/
/*#define PC_ONLY*/     /*H find_ ne reconnaît pas: .s .f .p .sh .csh  */
#define NL "\r\n"       /*H*/
//#define VC10			/*O Microsoft Visual C 10.- */
#define MSDEV41
#endif                  /*H*/
                        /*H*/
#ifdef UNIX             /*H*/
// #define UNIX_ONLY       /*H find_ ne reconnaît pas: .BAS .PAS .FOR ... */
#endif                  /*H*/
                        /*H*/

/*H #D *************************************************************************************/
/*H *** #Define OPTIONS DE COMPILATION:  options par défaut, redéfinissables: **************
          (#D pour l'extraction des options de compilation en ligne avec l'option CD3='#') */
/*H****************** #Define 'l' (ligne) commence par #define en 1ère colonne : ***********/
#define CD1 '%'   /*H #Define Option CD1 en 1ère colonne  prend fin avec NL                */
#define CD2 '<'   /*H #Define Option CD2 en 1ère colonne  prend fin avec NL                */
#define CD3 '!'   /*H #Define Option CD3 dans la ligne    prend fin avec NL                */
                  /*H #Define Option '!' commentaire Fortran 90 et ultérieurs              */
                  /*H #Define Option '%' commentaire postcript                             */
                  /*H #Define Option '#' commentaire shell ou pour Makefile voir option S
                                     ( le commentaire se termine avec new_line )           */
                  /*H #Define Option '\'' commentaires Basic                               */
                  /*H #Define Option ';'  commentaires assembleur                          */
/*H ***************** #Define Option 'p' (dans la page) #define en 1ère colonne : **********/
#define CD4 '\"'  /*H #Define Option CD4 = "  debut de commentaire                         */
#define CD5 '\"'  /*H #Define Option CD5 = "  fin de commentaire                           */
                  /*H #Define **************************************************************/
#define FULL_LINE /*H #Define Option de compil. copier toute la ligne                      */
/*H #D *************************************************************************************/



				/*H*/
#define VERSION "130514"	/*H*/
				/*H*/
#define MAX     85		/*H longueur des buffers des path source et doc */
#define STX     0x2		/*H Start Text */
#include <stdio.h>		/*H*/
				/*H*/
#ifdef PC			/*H*/
#include <conio.h>		/*H*/
#include <process.h>		/*H*/
#include <io.h>			/*H*/
#endif				/*H*/
#ifdef VC10			/*H Microsoft Visual C 10.- */
	#define putch _putch	/*H ISO C++ */
	#define getch _getch	/*H ISO C++ */
	#define access _access	/*H ISO C++ */
#endif				/*H*/
				/*H*/
#ifdef MSDEV41			/*H*/
	//#define STD_C		/*H SVr4, 4.3BSD, C89, C99.*/
	#include <string.h>	/*H*/
#endif				/*H*/
				/*H*/
#ifdef UNIX			/*H*/
#define NL "\n"                 /*H*/
   #define exit return
	#define bool int
	//#define STD_C		/*H SVr4, 4.3BSD, C89, C99.*/
	//#define getch() getchar()*/ defined in mkd.c
	#define putch putchar	/*H*/
#include <signal.h>		/*H*/
#include <sys/file.h>		/*H*/
#include <string.h>		/*H*/
#endif				/*H*/

