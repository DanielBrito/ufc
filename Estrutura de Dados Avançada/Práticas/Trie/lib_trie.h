#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max_alfabeto 26

typedef struct TrieNo{ 

    struct TrieNo *filhos[max_alfabeto]; 
    bool fimPalavra;

}Tno; 
	
Tno* constuir(void);
void inserir(Tno* raiz, char *chave, int tamanho);
bool buscar(Tno* raiz, char *chave, int tamanho);

void menu();