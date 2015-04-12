#
# ppc3 makefile
#
#

#
# use which C compiler?
#
CC = gcc

#
# use which parser generator?
#
YACC = bison

#
# Yacc/Bison flags
#
YFLAGS = -d -y

#
# use which scanner generator?
#
LEX = flex

#
# compile everything for debugger?
#
#yes
CFLAGS = -g
#no
#CFLAGS =

#
# which back end?
#
BACKEND = backend-x86

PPC3H	= defs.h types.h tree.h symtab.h $(BACKEND).h

PPC3OBJ = main.o message.o symtab.o types.o tree.o utils.o gram.o scan.o $(BACKEND).o


#
# For backup function
#
CURRDIR := ../$(notdir $(patsubst %/,%,$(shell pwd)))

BACKUPFOLDER = ../CompilersBackup

PROJECTNAME = pas-proj2

#
# For tesing function
#
FILEIN = ./aaaIN.txt
#Part2/test/T2L80_ok.pas

ERRORIN = Part2/test/T2L80_err.pas

FILEOUT = ./aaaOUT.txt

ERROROUT = ./aaaERRORout.txt


# ppc3 rules
#
ppc3     : $(PPC3OBJ)
	$(CC) $(CFLAGS) $(PPC3OBJ) -o ppc3

# dependencies for compiler modules

main.o: main.c defs.h types.h symtab.h

types.o: types.c types.h symtab.h message.h

symtab.o: symtab.c types.h symtab.h message.h

$(BACKEND).o: $(BACKEND).c $(BACKEND).h message.h defs.h

message.o: message.c message.h defs.h

utils.o: utils.c symtab.h message.h defs.h $(BACKEND).h

gram.o : gram.y $(PPC3H)
	$(YACC) $(YFLAGS) gram.y
	$(CC) $(CFLAGS) -c y.tab.c
	mv y.tab.o gram.o

scan.o : scan.l gram.o $(PPC3H)
	$(LEX) scan.l
	$(CC) $(CFLAGS) -c lex.yy.c
	rm lex.yy.c
	mv lex.yy.o scan.o

y.output: gram.y
	$(YACC) -v -y gram.y

clean:
	-rm -f ppc3 *.o y.tab.h y.output y.tab.c *.err *.s *~ aaaOUT.txt aaaERRORout.txt

backup:
	-make clean
	-mkdir -p $(BACKUPFOLDER)
	-tar cvf ../$(PROJECTNAME).tar $(CURRDIR)
	-gzip ../$(PROJECTNAME).tar
	-mv ../$(PROJECTNAME).tar.gz $(BACKUPFOLDER)/$(PROJECTNAME).tar.gz

test:
	-make -B
	-./ppc3 < $(FILEIN) > $(FILEOUT) 2> $(ERROROUT)

error:
	-./ppc3 < $(ERRORIN) > $(FILEOUT) 2> $(ERROROUT)
