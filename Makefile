CC = gcc
CFLAGS = -lgraph
EXE = jeu
OFILES = InterfaceGraphique.o timer.o easy.o medium.o hard.o
 
but : ${EXE}
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}

clean :
	-rm -f ${OFILES}

.PHONY : but clean