all: exe

lista.o: lista.c
	gcc -c lista.c -g
main.o: exe.c
	gcc -c exe.c -g
exe: exe.o lista.o
	gcc -o exe.x exe.o lista.o -g

clean:
	rm -f *.x *.o
