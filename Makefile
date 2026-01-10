run: prog
	./prog lion chien

prog: selection.o affichage.o uvsqgraphics.o lire_ecrire.o transfo.o main.o
	gcc -Wall -o prog selection.o affichage.o uvsqgraphics.o lire_ecrire.o transfo.o main.o `sdl2-config --cflags --libs` -lSDL2_ttf -lm

transfo.o: transfo.c transfo.h
	gcc -Wall -I/usr/include/SDL2 -c transfo.c -o transfo.o

lire_ecrire.o: lecture_ecriture.c lecture_ecriture.h 
	gcc -Wall -I/usr/include/SDL2 -c lecture_ecriture.c -o lire_ecrire.o

affichage.o: affichage.c affichage.h 
	gcc -Wall -I/usr/include/SDL2 -c affichage.c -o affichage.o

uvsqgraphics.o: uvsqgraphics_2.c uvsqgraphics_2.h
	gcc -Wall -I/usr/include/SDL2 -c uvsqgraphics_2.c -o uvsqgraphics.o

selection.o: selection.c selection.h
	gcc -Wall -I/usr/include/SDL2 -c selection.c -o selection.o

main.o: main.c transfo.h lecture_ecriture.h uvsqgraphics_2.h affichage.h selection.h
	gcc -Wall -I/usr/include/SDL2 -c main.c -o main.o

clean:
	rm -f *.o
	rm -f prog