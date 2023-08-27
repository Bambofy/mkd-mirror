# file: unix.mak (Makefile pour version LINUX UNBUNTU 6) mise à jour janvier 2012 par Clara
# modifié par JPL le 30/03/2012, 3/12/2013.
# UBUNTU syntax: sudo make -f unix.mak -d (see install...)
#
# Attention: avant de compiler, il faut valider les options de compilation
# dans version.h (notamment version UNIX ou version PC, ainsi que la langue)
#
# Use BINDIR /bin or /usr/bin or /usr/local/bin
# Lang : en and fr. See install_lang. See also install_mime_database.
#
# See install for more details

 ######################################
 ### UBUNTU version for mkd_R_13.10 ###
 ######################################

PGM     = mkd
BINDIR  = ./
BINMODE = 755

SRCS    = mkd.c asm.c basic.c cpp.c fortran.c pascal.c shell.c tri.c
HDRS    = version.h mkd.h asm.h basic.h cpp.h fortran.h pascal.h shell.c find.inc.c find.inc.h tri.h
OBJS    = mkd.o asm.o basic.o cpp.o fortran.o pascal.o shell.o tri.o
LIBS    =
CFLAGS  =  -O
LDFLAGS =
SPLINTFLAG = -weak

installation: $(BINDIR)/$(PGM) $(MANUALS) 

$(BINDIR)/$(PGM): $(SRCS) $(HDRS)
	-@echo "*********** update $(PGM) ***********"
	$(CC) $(CFLAGS) -o $(PGM) $(SRCS)
	@#$(CC) $(LDFLAGS) -o $(PGM) $(OBJS) $(LIBS)
	-@strip $(PGM) 					# clean ASM and LINK reloc.
	-@echo " -- update $(BINDIR)/$(PGM):" 		# install PGM in BINDIR
	-@if [ -d $(BINDIR) ]; then \
		cp -f $(PGM) $(BINDIR)/$(PGM);\
		chmod $(BINMODE) $(BINDIR)/$(PGM);\
		if [ $(BINDIR) = "/bin" ] || [ $(BINDIR) = "/usr/local/bin" ] ; then \
			ln -s $(BINDIR)/$(PGM) /bin/$(PGM);\
		fi \
	else \
		echo "couldn't find $(BINDIR)";\
	fi

$(MANUALS):
	-@echo "*********** Update manuals: See install ***********"

lint:
	-@echo "*** lint -> warnings (file), lint no longer exist ... ! install splint ***"
	splint $(SPLINTFLAGS) $(SRCS) > warnings
	more warnings

clean:
	rm -f $(OBJS)
