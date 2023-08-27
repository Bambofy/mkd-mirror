# file: Makefile (Makefile pour version LINUX UNBUNTU 6) mise à jour janvier 2012 par Clara
# modifié par JPL le 30/03/2012, 3/12/2013, 31/12/2013 pour empaquetage
# Only for packaging. see also INSTALL.sh in src directory
#
# Attention: avant de compiler, il faut valider les options de compilation
# dans version.h (notamment version UNIX ou version PC, ainsi que la langue)
#

 ################################################
 ### UBUNTU version for packaging mkd_R_13.10 ###
 ################################################

PGM     = mkd
SRC	= src
BINDIR  = usr/bin
BINMODE = 755

SRCS    = $(SRC)/mkd.c $(SRC)/asm.c $(SRC)/basic.c $(SRC)/cpp.c $(SRC)/fortran.c $(SRC)/pascal.c $(SRC)/shell.c $(SRC)/tri.c
HDRS    = $(SRC)/version.h $(SRC)/mkd.h $(SRC)/asm.h $(SRC)/basic.h $(SRC)/cpp.h $(SRC)/fortran.h $(SRC)/pascal.h $(SRC)/shell.c $(SRC)/find.inc.c $(SRC)/find.inc.h $(SRC)/tri.h
OBJS    = mkd.o asm.o basic.o cpp.o fortran.o pascal.o shell.o tri.o
LIBS    =
CFLAGS  =  -O
LDFLAGS =
SPLINTFLAG = -weak


$(PGM): $(SRCS) $(HDRS)
	-@echo "*********** update $(PGM) ***********"
	$(CC) $(CFLAGS) -o $(PGM) $(SRCS)
	@#$(CC) $(LDFLAGS) -o $(PGM) $(OBJS) $(LIBS)
	-@echo " -- update $(BINDIR)/$(PGM):"
	-@if [ -d $(BINDIR) ]; then \
		mv -f $(PGM) $(BINDIR)/$(PGM);\
		chmod $(BINMODE) $(BINDIR)/$(PGM);\
	else \
		echo "couldn't find $(BINDIR)";\
	fi

# La recompilation du binaire est nécessaire 
install: mkd
	mkdir -p debian/mkd/usr/bin
	cp -rf usr debian/mkd/.
	make -d -C src-mkddocu install DESTDIR=../debian/mkd-doc

# mrproper for CDBS
mrproper:
	rm -rf *~
	rm -f $(PGM) $(BINDIR)/$(PGM)
	rm -f $(OBJS)

# clean for dh
clean :
	rm -rf *~
	rm -f $(PGM) $(BINDIR)/$(PGM)
	rm -f $(OBJS)

