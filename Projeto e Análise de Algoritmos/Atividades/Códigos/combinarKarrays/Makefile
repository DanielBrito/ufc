all: exe

modulos.o: modulos.c
	gcc -c modulos.c
main.o: main.c
	gcc -c main.c
exe: main.o modulos.o
	gcc -o main.x main.o modulos.o

clean:
	rm -f *.x *.o
