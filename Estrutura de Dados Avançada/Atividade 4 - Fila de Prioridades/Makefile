all: exe

modulo.o: modulo.c
	gcc -c modulo.c
main.o: main.c
	gcc -c main.c
exe: main.o modulo.o
	gcc -o main.x main.o modulo.o

clean:
	rm -f *.x *.o
