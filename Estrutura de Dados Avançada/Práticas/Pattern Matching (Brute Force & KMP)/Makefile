all: exe

modulo.o: modulo.c
	gcc -c modulo.c -g
main.o: main.c
	gcc -c main.c -g
exe: main.o modulo.o
	gcc -o main.x main.o modulo.o -g

clean:
	rm -f *.x *.o

