/*P
	NOM DU FICHIER: mkd.c
	PROJET INITIAL: mkd console linux & Windows 7
	DOSSIER INITIAL : mkdoc3.12 Centre d'Electronique de Montpellier
	PROGRAMMEUR: Jean-Paul LOUYOT
	DATE: 18/12/2009
	MODIFICATIONS:
	le: 10/03/2010 par JPL :  Mise à jour pour Visual C 10
	le: 25/03/2012 par Clara : internationalisation
	le: 31/03/2012 par jpl : internationalisation. Conversion du fichier
                                 au format UTF-8
	le: 18/04/2013 par jpl : mise à jour pour version 2013
	le: 11/05/2013 par jpl : pour compilation avec les fichiers mis à jour
*/
// le: ../../.. par

/*H  
	// File: mkd.c
	//// internal functions
	// int main (int argc, char * argv[]);
	// int tolower(int c);
	// int toupper(int c);
	// int getch(stdin);
	//// external special functions in internationalisation.h
	// char * gettext (const char * msgid);
*/

#include "version.h"
#include "mkd.h"
#include "internationalisation.h"

unsigned char A,B,C,F,P,S,a,f,j,l,n,p,s,t,v,w; /*P ajout n et v version 3.1 */
/* static */ char codes[5] = {0,0,0,0,0};


/** #######################################
    #           SOUS PROGRAMMES           #
    ####################################### */


// #include "asm.inc.c"	    //P old version see asm.c
// #include "basic.inc.c"   //P old version see basic.c
// #include "c.inc.c"	    //P old version see cpp.c
// #include "fortran.inc.c" //P old version see fortran.c
// #include "pascal.inc.c"  //P old version see pascal.c
// #include "shell.inc.c"   //P old version see shell.c
// #include "tri.inc.c"     //P old version see tri.c



 int tolower(int c)
// char c;
     {
         if( c >='A' && c <='Z' ) c=(c-'A')+'a';
         return(c);
     }

 int toupper(int c)
// char c;
     {
         if( c >='a' && c <='z' ) c=(c-'a')+'A';
         return(c);
     }

#ifdef UNIX
 int getch()
     {
         int c;
         c=getc(stdin);
         if (c=='\r')c='\n';
         return(c);
     }
#define exit return //P c++
#endif




/** #######################################
    #               MAIN()                #
    ####################################### */


 int main (int argc, char * argv[])
// int argc;
// char *argv[];
 { /*S main */
//O Internationalization Initialization 
//  i18n: initializes the entire current locale of the program as per 
//  environment variables set by the user
     setlocale( LC_ALL, "" );    
//  i18n: Indicate the path of the i18n catalog file
     bindtextdomain( "mkd", "/usr/share/locale" );    
//  i18n: sets the message domain
     textdomain( "mkd" );

     char *fprj;       // nom du fichier de projet s'il existe
     char fdoc[MAX];   // nom du fichier cible
     char fsrc[MAX];   // nom du fichier source
     extern  char codes[];  // codes
     extern unsigned char A,B,C,F,P,S,a,f,j,l,n,p,s,t,v,w; // booléennes
     int i,k;          // compteurs
     char isource;     // position nom du fichier source dans path source
     char itarget;     // position fin du path_target avec '*' ou ':'(PC)
     char ktar;        // position du '.' dans p_target
     static char O;    // booléen =1 si option validée
     static char L;    // booléen =1 si option langage
     register int c;   // char (variable)
     int c1;           // char (variable) pour version PC
     int ret = 0;      // essai

     FILE *pfprj;  // fichier de projet       */
     FILE *pnfile; // fichier source
     FILE *pfdoc;  // fichier cible

/*##########################################################################*/
/*O si argc < 3 ou arc > 5: */
/*##########################################################################*/
/*O alors ecrire 'USAGE', donner la syntaxe puis quitter */
     if ( argc < 3 || argc > 5 )
     { //S argc <3 ou argc > 5 : syntaxe

#ifdef PC
        ret = printf(gettext("mkd PC version, Release %s, USAGE:\n"),VERSION);
        printf(gettext("syntax: mkd [-ABCFPSafjlnpstvw] char_codes path_source [path_target]\n"));
        puts  (gettext("    or: mkd ? .See also mkd.doc or manual."));
#endif

#ifdef UNIX
        printf(gettext("mkd UNIX version, Release %s, USAGE:\n"),VERSION);
        printf(gettext("syntax: mkd [-ABCFPSafjlnpstvw] char_codes path_source [path_target]\n"));
        puts  (gettext("    or: mkd \\? .See also nanual: \'man mkd\'"));
#endif

        if( argc==2 && argv[1][0]=='?' )
        { //S argc=2 et ?
           printf(gettext(" --> options:\n"));
           printf(gettext("      -A decode Assembler comment style only\n"));
/* #ifndef UNIX_ONLY */
           printf(gettext("      -B        Basic style\n"));
/* #endif */
           printf(gettext("      -C        C++ style\n"));
           printf(gettext("      -F        Fortran 77 style\n"));
           printf(gettext("      -P        Pascal style\n"));
/* #ifndef PC_ONLY */
           printf(gettext("      -S        Shell style\n"));
/* #endif */
           printf(gettext("      -a append target file\n"));
           printf(gettext("      -f:\n"));

#ifndef UNIX_ONLY
           printf(gettext("          find language ( .ASM .BAS .C .FOR .PAS .PRO )\n"));
#endif

#ifndef PC_ONLY
           printf(gettext("          find language ( .s .S .c .h .i .f .F .r .p .sh .csh )\n"));
#endif

           printf(gettext("      -j use only with project sources file.\n"));
           printf(gettext("      -l and p;   line:  (compil.: %c or %c in first column or %c in line)\n"),CD1,CD2,CD3);
           printf(gettext("                  page:  (compil.: begin with %c and end with %c)\n"),CD4,CD5);
           printf(gettext("      -n insert line number\n"));
           printf(gettext("      -s copy and add to screen\n"));
           printf(gettext("      -t copy the comment only\n"));
           printf(gettext("      -v verbose\n"));
           printf(gettext("      -w overwrite (default option: switch off)\n"));
           printf(gettext(" --> char_codes: all ASCII "));

#ifdef PC
           printf(gettext("except space:' '  (5 char max)\n"));
           printf(gettext("                 example codes = UM or *OPTw or *HOS or ** for all\n"));
#endif

#ifdef UNIX
           printf(gettext(" (5 char max)\n"));
           printf(gettext("                 example codes = UM or \\*OPTw or '* HOS' or '**' for all\n"));
#endif

           printf(gettext(" --> path_source: source file (option j: if it is a project file) \n"));
           printf(gettext(" --> path_target: target file\n"));

#ifdef UNIX
           printf(gettext("Example: mkd -Csnv '*S' file.c \\*.verif_struct\n"));
#endif

#ifdef PC
           printf(gettext("Example: mkd -Cs *Snv file.c *.str\n"));
#endif
           printf(gettext(".Exit 2\n"));
           exit(2); /* Pour un contrôle éventuel (make) */
        } //S argc=2 et ?
     } //S argc <3 ou argc > 5 : syntaxe

/*O sinon exécuter la suite de la commande: */
     else
        { /*S corps */

/*O   valider QUIT par CTRL \ */
#ifdef UNIX
        signal(SIGQUIT,SIG_DFL);
#endif

/*www n'est pas utile lorsque break est 'on' avant lancement de mkd
 éliminer cette procédure évite la recherche de command.com sur disque.
#ifdef PC
        c=system("BREAK ON");
#endif
www*/

/*O    init fsrc & fdoc buffers */
           for(i=0;i<MAX;fsrc[i]='\0',fdoc[i]='\0',++i);
/*O    init options par défaut */
           {A=0;B=0;C=0;F=0;P=0;S=0;a=0;f=0;j=0;l=0;n=0,p=0;s=0;t=0;v=0;w=0;} /*O*/
           O=0; /* Option=0 */
/*O    si argc>3 */
           if (argc>3)
           { /*S argc>3 */
/*O       si en 2ème paramètre 1er char = '-' décoder les options */
              if( argv[1][0]=='-')
              { /*S*/
/*O          initialiser les paramètres du tant que */
                 O=1; /* Option=1 */
                 c=1;
                 i=1;
/*O          tant que pas fin paramètres options & (5 options max) */
                 while (c != '\0' && i < 13)
                 { /*S*/
/*O             valider les options */
                    if ((c=argv[1][i]) == 'a') a=1;
                    else if (c=='w') w=1;
                       else if (c=='l') l=1;
                           else if (c=='p') p=1;
                              else if (c=='j') j=1;
                                 else if (c=='f') f=1;
                                    else if (c=='s') s=1;
                                       else if (c=='t') t=1;
                                          else if (c=='A') A=1;
                                             else if (c=='B') B=1;
                                                else if (c=='C') C=1;
                                                   else if (c=='F') F=1;
                                                      else if (c=='P') P=1;
                                                         else if (c=='S') S=1;
                                                            else if (c=='n') n=1;
                                                               else if (c=='v') v=1;
                    i++;
                 } /*S*/
/*O          si A+B+C+F+P+S > 1 il y a erreur le dire et quitter */
              if((L=A+B+C+F+P+S)>1)
                 {
                 printf(gettext("Syntax error: Too many 'Language' options:\n"));
                 printf(gettext(" A or B or C or...please.\n.Exit 2\n"));
                 exit(2);
                 }
/*O          sinon si option langage = 1 imposer (find) f = 0 */
              else if(L==1)
                 {
                 f=0;
                 }
/*O             sinon si pas d'option de langage et p=1 ou l=1 alors f=0 */
                 else if (L==0 && p==0 && l==0) f=1;

/*O          si a=1 et w=1 alors a=w=0 */
                 if (a==1 && w==1)
                 {
                 if (v) printf(gettext("Options a or w please... "));
                 a=w=0;
                 }
              } /*S*/
              /*wwwO sinon écrire Option syntax error (OPTION DE COMPILATION) */
              /*www else {printf("Option '-' syntax error\n");exit(2);} */
           } /*S argc>3 */

/*O    si langage et mode verbose : */
        if(L && v)
           { /*SL*/
/*O       donner les options a l'écran */
           printf (gettext("Force language comment, style "));
           if(A)printf(gettext("ASSEMBLER\n"));
           else if(B)printf(gettext("BASIC\n"));
              else if(C)printf(gettext("C\n"));
                 else if(F)printf(gettext("FORTRAN\n"));
                    else if(P)printf(gettext("PASCAL\n"));
                       else if(S)printf(gettext("SHELL\n"));
           } /*SL*/

           if (v) printf (gettext("Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d\n"),a,f,j,l,n,p,s,t,w);

/*###########################################################################*/
/*O    si ( argc > 3 et Opt ) examiner les cas *. *.* pour path_target=""    */
/*###########################################################################*/
        if (argc > 3+O && ((c=argv[O+3][0])=='.'||c=='*') )
           { /*S cas ramenés */
           if(c=='*')
              { /*S *. *.* */
              if(argv[O+3][1]=='.'&&((c=argv[O+3][2])=='*'||c=='\0') )argc=O+3;
              } /*S * */
           else
              { /*S . */ /*P même répertoire */
              if(argv[O+3][1]=='\0')argc=O+3;
/*      Les cas '\*'.... sont examines plus loin */
              } /*S . */
           } /*S cas ramenés */

/*##########################################################################*/
/*O    si argc<4 ou (argc<5 avec Options)
                  - ligne de commande "mkd -options char_codes path"
                  -                ou "mkd char_codes path"
                  - (source et dest auront mÃªme path avec suffixe différent) */
/*###########################################################################*/
           if (argc<4+O)
           { /*S même path */

/*O       alors si j=1 fprj=4ème argument de la ligne de commande */
              if (j==1) fprj=argv[3]; /* fichier projet si j */

/*O       fsrc=O+2ème arg. de la ligne de commande a copier dans fsrc */
              { /*S source */
              k=0;isource=0;
              c=1;
#ifdef PC
              if(argv[O+2][1]==':')isource=2;
#endif
              for (i=0; c != '\0' && i < MAX-5;++i)
                 { /*S*/
                 if((c=argv[O+2][i])=='.')k=i; /* pour find */
#ifdef PC
                 if(c=='\\')isource=i+1;
#endif
#ifdef UNIX
                 if(c=='/')isource=i+1;
#endif
                    else if(c=='*')
                    { /*S*/
                    printf(gettext("Syntax error '*' in path_source.\n.Exit 2\n"));
                    exit(2);
                    } /*S*/
                 fsrc[i]=c;
                 } /*S*/
#ifdef PC
/*O             si  '\:'  adresser un message d'erreur et quitter */
                 if (isource==1&&argv[O+2][1]==':')
                 { /*S*/
                 printf(gettext("Arg. syntax error '\\:'\n.Exit 2 \n"));
                 exit(2);
                 } /*S*/
#endif

/*O             si find est positionne et pas j: chercher le langage */
                 if(f&&!j)
                 { /*S*/
                 // puts("\nTEST: f positionné et pas j ... rechercher avec find"); //T
#include"find.inc.c"

              if (j==1) fprj=argv[O+2]; /* fichier projet si j trouve */
                 } /*S*/
              } /*S source */



/*O       recopier le nomfichier sans path dans fdoc et noter l'emplacement du point s'il existe */
               k=0;
              for ( i = 0 ;(c=argv[O+2][i+isource]) != '\0' && i < MAX-5; ++i )
              { /*S*/
               fdoc[i]=c;
               if(c=='.')k=i;
              } /*S*/
/*O       si le source a le suffixe .DOC l'ecrire et quitter le pgm  */
              if(k)i=k;
              if ( fdoc[i]=='.' && ((c=(fdoc[i+1]))=='d'||c=='D')
                                && ((c=(fdoc[i+2]))=='o'||c=='O')
                                && ((c=(fdoc[i+3]))=='c'||c=='C'))
                 { /*S*/
                 printf(gettext("Syntax error: path_source, suffixe '.doc'\n.Exit 2\n"));
                 exit(2);
                 } /*S*/
/*O       sinon donner le suffixe .doc au fichier documentaire */
              else
              { /*S*/
              fdoc[i] = '.'  ;
              fdoc[i+1] = 'd' ;
              fdoc[i+2] = 'o' ;
              fdoc[i+3] = 'c' ;
              fdoc[i+4] = '\0' ;
              } /*S*/
           } /*S meme path */


/*###########################################################################*/
/*O    sinon si ( argc > 3 et Opt )
                     -ligne de commande "mkd char_codes path_src path_target
                     -     ou " mkd -options char_codes path_src path_target
                     -(path doc et path src seront différents) */
/*##########################################################################*/
           else if (argc > 3+O)
              { /*S path différents */
/*O          copier les noms de fichier: */
/*O             si j=1 fprj=4ème argument de la ligne de commande */
                    if (j==1) fprj=argv[3];  /* 3 = O+2 */


/*              fsrc est O+2ème arg. de la ligne de commande a copier dans fsrc */
/*O             copier le path source dans fsrc pour évaluation des paramètres */
                    { /*S source */
                    isource=0;itarget=0;
#ifdef PC
                    if(argv[O+2][1]==':')isource=2;
#endif

                    for (i=0; (c=argv[O+2][i]) != '\0' && i < MAX-1;++i)
                       { /*S examen des positions de '/' et '.' */
                       if(c=='.')k=i;  /* pour find */
#ifdef PC
                       else if(c=='\\')isource=i+1;  /* '\:' n'est pas evalue */
#endif
#ifdef UNIX
                       else if(c=='/')isource=i+1;
#endif
                          else if(c=='*')
                          { /*S*/
                          printf(gettext("Syntax error '*' in path_source.\n.Exit 2\n"));
                          exit(2);
                          } /*S*/
                       fsrc[i]=c;
                       } /*S examen des positions de '/' et '.' */
                       fsrc[i]='\0';

#ifdef PC
/*O                   si  '\:'  adresser un message d'erreur et quitter */
                      if (isource==1&&argv[O+2][1]==':')
                       { /*S*/
                       printf(gettext("Arg. syntax error '\\:'\n.Exit 2\n"));
                       exit(2);
                       } /*S*/
#endif
/*O                si find est positionne et pas j: chercher le langage */
                    if(f&&!j)
                       { /*S*/
#include "find.inc.c"
/*O                   si le fichier est un fichier projet affecter le nom a fprj */
                       if (j==1) fprj=argv[O+2]; /* fichier projet si j trouve */
                       } /*S*/
                    } /*S source */


/*O             traitement du dernier argument de la ligne de commande */
/*O                reperer  '/ *' ou ':' et '.' dans fdoc */
                    ktar=0;itarget=0;c=1;
#ifdef PC
                    if(argv[O+3][1]==':')itarget=2;
                    for (i=0; c!='\0' && i<MAX-1 ; ++i)
                       { /*S*/
                       if((c=argv[O+3][i])=='\\')
                          { /*S*/
                          if((c=argv[O+3][i+1])=='*')itarget=i+1;
/*O                      si  '\\0' erreur de syntaxe quitter */
                          if(c=='\0')
                             { /* err */
                             printf(gettext("Path_target: syntax error at or near '\\'\n.Exit 2\n"));
                             exit(2);
                             } /* err */
                          } /*S*/
                       else if(c=='.')ktar=i;
                       } /*S*/
#endif
#ifdef UNIX
                    c=1;
                    for (i=0; c!='\0' && i<MAX-1 ; ++i)
                       { /*S*/
                       if((c=argv[O+3][i])=='/')
                          { /*S*/
                          if((c=argv[O+3][i+1])=='*')itarget=i+1;
/*O                      si  '/ \0' erreur de syntaxe quitter */
                          if(c=='\0')
                             { /* err */
                             printf(gettext("Path_target: syntax error at or near '/'\n.Exit 2\n"));
                             exit(2);
                             } /* err */
                          } /*S*/
                       else if(c=='.')ktar=i;
                       } /*S*/
#endif
/*O                si nomfichier commence par '*': '/ *' ou ':' ou target commence par '*': */
                    if(itarget||argv[O+3][0]=='*')
/*O                alors: */
                    { /*S*/
/*O                   si * n'est pas en 1ere position copier le path target dans fdoc tq pas '*' */
                       if(itarget){for(i=0;i<itarget;i++)fdoc[i]=argv[argc-1][i];}
/*O                   concaténer le nom du fichier source  */
                       k=0;
                       for(i=0;(c=argv[argc-2][i+isource]) !=0 && i < (MAX-5); ++i)
                       { /*S*/
                          fdoc[i+itarget]=c;
/*O                      si il y a un point, noter la dernière place */
                          if(c=='.') k=i+itarget; /* position du dernier '.' dans la recopie */
                       } /*S*/
/*O                   ajouter le suffixe: */
/*O                      si le '.' existe dans le path_target */
                          if( argv[argc-1][ktar]== '.')
                          { /*S*/
/*O                         si c'est .* ou s'il n'est pas suivi d'une chaÃ®ne */
                             if( (c=argv[argc-1][ktar+1]) =='\0'||c=='*')
/*O                         alors donner le suffixe .doc au fichier documentaire */
                             { /*S*/
                             if(k)i=k;
                             fdoc[i] = '.'  ;
                             fdoc[i+1] = 'd' ;
                             fdoc[i+2] = 'o' ;
                             fdoc[i+3] = 'c' ;
                             fdoc[i+4] = '\0' ;
                             } /*S*/
/*O                         sinon (le '.' existe) concaténer le suffixe demande */
                             else
                             { /*S*/
                             for(i=ktar;(c=argv[argc-1][i])!='\0'&&k<(MAX-1);++i)
                                { /*S*/
                                fdoc[k]=c;
                                k++;
                                } /*S*/
                             fdoc[k]='\0';
                             } /*S*/
                          } /*S*/
/*O                      sinon le nom du suffixe est indéterminé */
                          else
                          { /*S*/
                          printf(gettext("Path target: suffixe not determined.\n"));
                          fdoc[k]='\0';
                          } /*S*/
                    } /*S*/

/*O                sinon: xxx xxx. xxx.* .xxx .*  */
                    else
                    { /*S else */
/*O                si le point existe: (abc. abc.def abc.* .abc .*) */
                       if( argv[argc-1][ktar]== '.')
                       { /*S '. */
/*O                   copier le nom du fichier target  */
                       k=0;c=1;
                       for(i=0;(c=argv[argc-1][i]) !=0 && i < (MAX-5); ++i)
                          { /*S*/
                          fdoc[i]=c;
/*O                      noter la position du point dans la recopie */
                          if(c=='.') k=i;
                          } /*S*/
/*O                   ajouter le suffixe: */
/*O                      si le point est suivi de '*' ou rien: */
                          if( (c=argv[argc-1][k+1])=='\0'||c=='*')
/*O                      alors donner le suffixe .doc au fichier documentaire */
                          { /*S xxx.* */
                          fdoc[k] = '.'  ;
                          fdoc[k+1] = 'd' ;
                          fdoc[k+2] = 'o' ;
                          fdoc[k+3] = 'c' ;
                          fdoc[k+4] = '\0' ;
                          } /*S xxx.* */
/*O                      sinon (le '.' existe) concaténer le suffixe demande */
                          else
                          { /*S xxx.abc */
                          for(i=0;(c=argv[argc-1][i+ktar])!='\0'&&k<(MAX-1);++i)
                             { /*S*/
                             fdoc[i+k]=c;
                             } /*S*/
                          fdoc[i+k]='\0';
                          } /*S xxx.abc*/
                       } /*S '.' */

/*O                   sinon le nom du suffixe est indéterminé */
                       else /* abcde */
                       { /*S*/
                       for(i=0;(c=argv[argc-1][i]) != '\0' && i<MAX-1;fdoc[i]=c,++i);
                       printf(gettext("Path target: suffixe not determined.\n"));
                       fdoc[i]='\0';
                       } /*S*/
                    } /*S else */
              } /*S path differents */

/*########### controle des arguments ########################################*/
/*O    si le fichier source est identique au fichier target : */
        k=1;
        for(i=0;k>0&&i<MAX;i++)
           { /*S*/
#ifdef PC
           c=toupper(fdoc[i]);
           c1=toupper(fsrc[i]);
           if(c>0 && c!=c1)k=0;                         /* exit */
           else if(c=='\0'|| fsrc[i]=='\0')k=0;         /* exit */
#endif
#ifdef UNIX
           if((c=fdoc[i])>0&&c!=fsrc[i])k=0;            /* exit */
           else if(c=='\0'|| fsrc[i]=='\0')k=0;         /* exit */
#endif
/*Test     printf("%c%c",c,fsrc[i]); */
           } /*S*/
       if(c=='\0'&& fsrc[i]=='\0')
/*O    alors : */
           { /*S*/
/*O       envoi du message d'erreur et quitter */
           printf(gettext("Syntax error: (path_source : \'%s\') == (path_target = \'%s\')\n"),fsrc,fdoc);
           printf(".Exit 2 \n");
           exit(2);
           } /*S*/

/*## FIN DE L'EXAMEN DES ARGUMENTS ##########################################*/

/*O    copier les codes dans le buffer codes */
           for ( i = 0 ; *(argv[1+O]+i) != '\0' && i < 5 ; ++i) codes[i] = *(argv[1+O]+i);
           if(codes[0]=='*'&&codes[1]=='*')codes[0]=0;
           /*T printf("code nx1 pour test: %c\n",codes[0]); T*/

/*O    si option v écrire le nom du fichier documentaire sur la sortie standard */
        if(v) printf(gettext("doc file : \'%s\' \n"), fdoc);
/*O    si pas d'option a ni w vérifier l'existence et ses protections */
        if (w==0 && a==0)
           { /*S si !a !w */
/*O       si le fichier existe: */
           if( (access(fdoc, 00 )) == 0 )
/*O       alors si il n'est pas protégé en écriture */
              if( (access(fdoc, 02 )) == 0 )
              { /*S*/
/*O          alors demander si overwrit ...si pas 'y'es quitter le programme */
                 {
                 printf(gettext("\n OVERWRIT \'%s\' ...  y?\n"),fdoc);
                 if ( (c=(getch()))=='y' || c=='Y');
                 else
                    { /*S*/
                    printf(gettext(".Exit 1\n"));
                    exit(1);
                    } /*S*/
                 }
              } /*S*/
/*O          sinon préciser qu'il existe et est protégé puis quitter avec retour = 2 */
              else
              { /*S*/
                 printf(gettext("%s is write protected.\n"), fdoc);
                 puts(gettext(".Exit 2\n"));
                 exit(2);
              } /*S*/
/*O       faire option w=1 (puisque overwrit) */
              w=1;
           } /*S si !a !w */


/*O    si option a ouvrir fdoc en ajout */
           if (a==1)
           { /*S option a */
/*O       si erreur l'ecrire et sortir */
#ifdef VC10
			  if ( fopen_s( &pfdoc,fdoc,"ab") != 0 )
#else
              if((pfdoc = fopen(fdoc,"ab")) == NULL)
#endif
              {
              printf(gettext("fopen file \'%s\' error for append\n.Exit 2\n"),fdoc);
              exit(2);
              }
           } /*S option a */
/*O       sinon si option w ouvrir fdoc en écriture */
              else if (w==1)
                 { /*S option w */
/*O             si erreur l'écrire et sortir */
#ifdef VC10
					 if (fopen_s(&pfdoc,fdoc,"wb") != 0)
#else
                     if((pfdoc = fopen(fdoc,"wb")) == NULL)
#endif
                     { /*S*/
                     printf(gettext("fopen file \'%s\' error for overwrit\n.Exit 2\n"),fdoc);
                     exit(2);
                     } /*S*/
                 } /*S option w */
/*T          sinon ecrire message d'erreur -a -w pas trouve */
                 else /* ne doit jamais arriver.... */
                 { /*Test*/
                 printf(gettext("error option -a or -w not found\n"));
                 exit(255);
                 } /*Test*/

/*O    si option j */
           if (j==1)
           { /*S si option j */
/*O       écrire le nom du fichier projet a l'écran */
              printf(gettext("project file : \'%s\' \n"), fprj);
/*O       si erreur d'ouverture écrire not found et quitter le programme */
#ifdef VC10
			  if ( fopen_s(&pfprj,fprj,"r") != 0 )
#else
			  if (( pfprj = fopen ( fprj,"r" )) == 0 )
#endif
              { /*S*/
              printf (gettext("project file \'%s\' not found\n.Exit 2\n"),fprj);
              exit(2);
              } /*S*/
/*O       sinon : */
              else
              { /*S copy src & tri */
/*O          tant que pas fin de fichier projet */
                 while ( (c = getc(pfprj)) != EOF )
                 { /*S tq !EOF */
/*O             lire le nom du fichier a documenter */
                    ungetc(c,pfprj);
                    for (i=0 ; (c = getc(pfprj)) != '\n' && c != EOF ;
                         ++i) fsrc[i] = (char)c ;
                    fsrc[i] = '\0';
/*O             si le nomfichier existe et ne commence pas par '#' */
                 if( fsrc[0]!='\0' || fsrc[0]!='#' )
                 { /*S namefile exist */
/*O                si option v écrire le nom du fichier a documenter */
                    if(v) printf(gettext("\n\nfile for doc: \'%s\'\n"),fsrc);
/*O                si option f déterminer la place du point séparateur du langage */
                    if(f)
                    { /*S source */
                    k=0;
                    c=1;
/*O                   déterminer l'emplacement du point s'il existe */
                       for (i=0; fsrc[i] != '\0' && i < MAX-5;++i)
                      { /*S*/
                       if(fsrc[i]=='.')k=i;
                       } /*S*/
                    if(k)
#include "find.inc.h"
#include "find.inc.c"
                    } /*S source */

/*O                si le décryptage (langage) est détermine */
                    if(L==1||p||l)
/*O                alors: */
                       { /*S alors*/
/*O                   si l'ouverture du fichier source n'est pas correcte */
#ifdef VC10
                       if ( fopen_s(&pnfile,fsrc,"rb" ) != 0 )
#else
                       if  (( pnfile = fopen ( fsrc,"rb" )) == 0 )
#endif
/*O                   écrire file "nomfich" not found */
                       printf (gettext("file \'%s\' not found for read\n"),fsrc);
/*O                   sinon call tri ou langage */
                          else
                          { /*S else*/
/*O                      	si: on a option n ou s et mode bavard (option v) écrire le nom du fichier lu et les options */
							if(n||s||v) /*www modifié le 10/03/2010 par JPL */
							{ /*S si*/
								if(v)fprintf(pfdoc,gettext("%s\n(file %s :)"), NL, fsrc );
								if( v || s ) printf(gettext("\n\n(file %s :)\n"),fsrc);
								if(v)fprintf (pfdoc,gettext("Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d"),a,f,j,l,n,p,s,t,w);
								fprintf (pfdoc, "%s", NL );
							} /*S fin si*/
                          if(l||p)tri_(pfdoc,pnfile);
                          if(A)asm_(pfdoc,pnfile);
                             else if(B)basic_(pfdoc,pnfile);
                                else if(C)cpp_(pfdoc,pnfile); /*www modifié le 10 mars 2010 */
                                   else if(F)fortran_(pfdoc,pnfile);
                                      else if(P)pascal_(pfdoc,pnfile);
                                         else if(S)shell_(pfdoc,pnfile);
                                            else if(l==0&&p==0)printf(gettext("Error, language not determined !.\n"));
/*O                      fermer le fichier source */
                          if (fclose(pnfile))
                             { /*S si*/
                             printf(gettext("Closure error: \'%s\'\n.Exit 2\n"),fsrc);
                             /*www exit(2); */
                             } /*S fin si*/
                          } /*S fin else*/
                       } /*S fin alors*/
                    } /*S namefile exist */
                 } /*S tq !EOF */
/*O          fermer le fichier projet */
                 if (fclose(pfprj))
                 { /*S*/
                 printf(gettext("Closure error: \'%s\'\n.Exit 2\n"),fprj);
                 exit(2);
                 } /*S*/
              } /*S copy src & tri */
           } /*S si option j */
/*O    sinon: (pas option j) */
           else
           { /*S !j */
/*O       si option v écrire le nom du fichier a documenter */
              if(v) printf(gettext("\n\nfile for doc: \'%s\' \n"),fsrc);
/*O       si l'ouverture du fichier n'est pas correcte */
#ifdef VC10
			  if ( fopen_s(&pnfile,fsrc,"rb") != 0 )
#else
			  if (( pnfile = fopen ( fsrc,"rb" )) == 0 )
#endif
              { /*S*/
/*O          écrire file "nomfich" not found */
                 printf(gettext("file \'%s\' not found for read\n.Exit 2\n"),fsrc);
                 exit(2);
              } /*S*/
/*O       sinon call langage... */
              else
              { /*S*/
/*O          si: on a option n (on n'a pas l'option j) et mode bavard (option v) écrire le nom du fichier lu et les option */
              if(n||v||s) /*www modifié le 10/03/2010 par JPL */
                 { /*S*/
					if(v)fprintf(pfdoc,gettext("%s\n(file %s :)"), NL, fsrc );
					if( v || s ) printf(gettext("\n\n(file %s :)\n"),fsrc);
					if(v)fprintf (pfdoc,gettext("Options a=%d f=%d j=%d l=%d n=%d p=%d s=%d t=%d w=%d"),a,f,j,l,n,p,s,t,w);
					fprintf (pfdoc, "%s", NL );
                 } /*S*/
              if(l||p) tri_(pfdoc,pnfile);
              if(A)asm_(pfdoc,pnfile);
              else if(B)basic_(pfdoc,pnfile);
                 else if(C) cpp_(pfdoc,pnfile); /*www modifié le 10/03/2010 par JPL */
                    else if(F)fortran_(pfdoc,pnfile);
                       else if(P)pascal_(pfdoc,pnfile);
                          else if(S) shell_(pfdoc,pnfile);
                                else if(l==0&&p==0)
                                { /*S*/
                                printf(gettext("Error, programming language not found !.\n.Exit 2\n"));
                                exit(2);
                                } /*S*/
/*O          fermer le fichier depouille */
                 if (fclose(pnfile))
                 { /*S*/
                 printf(gettext("Closure error: \'%s\'\n.Exit 2 \n"),fdoc);
                 exit(2);
                 } /*S*/
              } /*S*/
           } /*S !j */
/*O    fermer le fichier documentaire */
           if (fclose(pfdoc))
           { /*S*/
           printf(gettext("Closure \'%s\' error\n.Exit 2\n"),fdoc);
           exit(2);
           } /*S*/
/*O    ecrire DOC "file_src" END */
           if(v) printf(gettext("\n\nDOC %s END\n"),fdoc);
        } /*S corps */
} /*S main */
