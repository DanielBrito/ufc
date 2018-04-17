all: main.x

lista.o: lista.c
	gcc -c lista.c -g

operacoes.o: operacoes.c
	gcc -c operacoes.c -g

main.o: main.c
	gcc -c main.c -g

main.x: main.o lista.o operacoes.o
	gcc -o main.x main.o lista.o operacoes.o

clean:
	rm -f *.x *.o