all: main

lista.o: lista.c
	gcc -c lista.c

indice.o: indice.c
	gcc -c indice.c

main.o: main.c
	gcc -c main.c

main.x: main.o lista.o indice.o
	gcc -o main.x main.o lista.o indice.o

clean:
	rm -f *.x *.o
