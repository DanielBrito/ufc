all: exe

lista.o: lista.c
	gcc -c lista.c
main.o: exe6.c
	gcc -c exe6.c
exe: exe6.o lista.o
	gcc -o exe6.x exe6.o lista.o

clean:
	rm -f *.x *.o
