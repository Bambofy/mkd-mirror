//P maj R3.11 04/01/91 par JPL
//P maj R 130509 alpha
              { /*S find */
/*O             mettre les drapeaux (options ABC... ) a 0 */
                 A=B=C=F=P=S=0;
                 L=0;
                 // c is a register int defined in mkd.c
                 int d; // local variables
                 int e, f, g;
                 if(v) printf("Find Souce File Language, \'%s\':   ",fsrc);
                 if(k)
                    { /*S chercher */
                    //T char buffer[10]; //T tests only
                    c = tolower(fsrc[k+1]);
                    if (c!='\0') d = tolower(fsrc[k+2]); else d='\0';
                    if (d!='\0') e = tolower(fsrc[k+3]); else e='\0';
                    // if (e!='\0') f = tolower(fsrc[k+4]); else f='\0';
                    // if (f!='\0') g = tolower(fsrc[k+4]); else g='\0';
                    // if (g!='\0') h = tolower(fsrc[k+3]); else h='\0';
                    //T buffer[0]=c; buffer[1]=d; buffer[2]=e; buffer[3]='\0'; //T Tests only
                    //T printf("\nTests: **** tolower extension = %s\n",buffer); //T tests only

#ifndef UNIX_ONLY // OK for PC and UNIX / LINUX. Not OK for C strict
                    if(c=='a'&&d=='s'&&(e=='m'||e=='i'))
                       {L=1;A=1;printf("ASM\n");}

                    else if( (c=='b'&&d=='a'&&e=='s')  || // bas
                             (c=='v'&&d=='b'&&e=='\0') ||  // Visual bacic
                             (c=='b'&&d=='a'&&e=='t')   // bat
                           )
                       {L=1;B=1;printf("BASIC\n");}

                    else if(
                            ( ((c=='c'||'h')&&d=='+'&&e=='+') || // c++, h++
                              ((c=='c'||'h')&&d=='-'&&e=='-') || // c--, h--
                              ((c=='c'||'h')&&d=='p'&&e=='p') || // cpp, hpp
                              (c=='c'&&d=='s'&&e=='s') ||  // css
                              (c=='c'&&d=='c'&&e=='\0') || // cc
                              (c=='h'&&d=='h'&&e=='\0') || // hh
                              (c=='c'&&d=='p'&&e=='\0') || // cp=c#
                              (c=='c'&&d=='s'&&e=='\0') || // cs=c#
                              (c=='c'&&d=='#'&&e=='\0') || // c#
                              (c=='c'&&d=='\0') || // C
                              (c=='h'&&d=='\0') || // h
                              (c=='d'&&d=='\0') || // D
                              (c=='p'&&d=='r')&&e=='o') || // pro prolog
//w see forward                  (c=='p'&&d=='l')&&d=='\0') || // pl perl, prolog
                              (c=='p'&&d=='h'&&e=='p') || // PHP
                              (c=='j'&&d=='a'&&e=='v') || // jav java
                              (c=='j'&&d=='s'&&e=='e') || // jse javascript
                              (c=='j'&&d=='s'&&e=='\0')   // js javascript
                            )
                              {L=1;C=1;printf("C or PROLOG\n");}

                     else if(c=='f'&&d=='o'&&e=='r')
                             {L=1;F=1;printf("FORTRAN\n");}

                     else if(c=='p'&&d=='a'&&e=='s')
                        {L=1;P=1;printf("PASCAL\n");}
#endif

#ifndef PC_ONLY // OK for UNIX / LINUX
                    if(c=='s'&&d=='\0')
                       {L=1;A=1;printf("Assembler\n");}

                    else if(c=='f'&&d=='\0')
                       {L=1;F=1;printf("Fortran\n");}

                    else if(c=='p'&&d=='\0')
                       {L=1;P=1;printf("Pascal\n");}

/*w Attention, il n'est pas coutumier de donner des extensions aux fichiers
    shell. Il serait utile de vérifier la première ligne si c est NULL. Pour
    cela il faudrait ouvrir et refermer le fichier source. */
                    else if( (c=='s'&&d=='h'&&e=='\0') || // sh
                             (c=='c'&&d=='s'&&e=='h')  || // csh
                             (c=='p'&&d=='l'&&e=='\0') || // pl perl
                             (c=='r'&&d=='b'&&e=='\0') || // rb ruby
                             (c=='p'&&d=='y'&&e=='\0') || // py python
                             (c=='p'&&d=='y'&&e=='w')  || // pyw python
                             (c=='r'&&d=='\0') // ratfor
                           )
                       {L=1;S=1;printf("Shell\n");}

#endif

#ifdef UNIX_ONLY // C strict not in use with mkd see version.h
                    else if((c=='c'||c=='h')&&d=='\0')
                       {L=1;C=1;printf("C strict\n");}
#endif

#ifndef ARGS_EXAM
                    else if( (c=='p'&&d=='r'&&e=='j') || // prj mkd
                             (c=='p'&&d=='j'&&e=='\0')   // pj mkd
                           )
                       {L=1;j=1;printf("Project file\n");}
#endif
                    } /*S chercher */
                    
/*O                si le langage n'est pas trouvé: */
                    if(!L)
/*O                alors: */
                    { /*S*/
/*O                   mettre les drapeaux (options ABC... ) a 0 */
                       A=B=C=F=P=S=0;
/*O                   demander le type de langage du fichier et positionner le drapeau */
                       printf("\n*** Source file: language not found. (Enter A,B,C,F,P,S,l or p)\n");
#ifndef ARGS_EXAM
                       if(!j)printf("*** For project file: exit and use option -j.\n");
#endif
                       printf("Enter ESCAPE for exit ?:");
                       if(j)printf("\b\bor space_bar for Ignore ?: ");
                       if((c=getch())==0x1B){ /*S*/ printf("\n.Exit 1\n");exit(1);} /*S*/
                       else if(c=='A'||c=='a')A=1;
                       else if(c=='B'||c=='b')B=1;
                       else if(c=='C'||c=='c')C=1;
                       else if(c=='F'||c=='f')F=1;
                       else if(c=='P'||c=='p')P=1;
                       else if(c=='S'||c=='s')S=1;
                       else if (c=='l')l=1;
                       else if(c=='p')p=1;
                       else 
                       { /*S*/
                          printf("\n.Exit 2\n"); exit(2);
                       } /*S*/
                       printf("\n");
                       L=A+B+C+F+P+S;
/*O                   si aucun drapeau langage n'est positionne envoyer BEL */
                       if(!(L==1||p||l))putch(0x7);
                       putch('\n');  
                    } /*S*/
              } /*S find */
