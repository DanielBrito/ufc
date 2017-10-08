all: exe

lista.o: lista.c
	gcc -c lista.c
main.o: exe3.c
	gcc -c exe3.c
exe: exe3.o lista.o
	gcc -o exe3.x exe3.o lista.o

clean:
	rm -f *.x *.o
