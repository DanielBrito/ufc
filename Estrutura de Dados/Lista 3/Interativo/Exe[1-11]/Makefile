all: exe

lista.o: lista.c
	gcc -c lista.c
main.o: exe.c
	gcc -c exe.c
exe: exe.o lista.o
	gcc -o exe.x exe.o lista.o

clean:
	rm -f *.x *.o
