run: prog
	./prog voiture

prog: transfo.o main.o
	gcc -Wall -o prog transfo.o main.o

transfo.o: transfo.c transfo.h
	gcc -Wall -c transfo.c -o transfo.o

main.o: main.c transfo.h
	gcc -Wall -c main.c -o main.o

clean:
	rm -f *.o
	rm -f prog