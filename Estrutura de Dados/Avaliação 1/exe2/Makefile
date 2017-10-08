all: exe

lista.o: lista.c
	gcc -c lista.c
main.o: exe2.c
	gcc -c exe2.c
exe: exe2.o lista.o
	gcc -o exe2.x exe2.o lista.o

clean:
	rm -f *.x *.o
