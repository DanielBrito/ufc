all: exe

lista.o: lista.c
	gcc -c lista.c
main.o: exe4.c
	gcc -c exe4.c
exe: exe4.o lista.o
	gcc -o exe4.x exe4.o lista.o

clean:
	rm -f *.x *.o
