all: exe

modulo_trie.o: modulo_trie.c
	gcc -c modulo_trie.c -g
main.o: main.c
	gcc -c main.c -g
exe: main.o modulo_trie.o
	gcc -o main.x main.o modulo_trie.o -g

clean:
	rm -f *.x *.o

