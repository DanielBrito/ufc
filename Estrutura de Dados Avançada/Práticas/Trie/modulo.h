#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max_alfabeto 26
 
typedef struct TrieNo{ 

    struct TrieNo *filhos[max_alfabeto]; 
    bool fimPalavra;

}Tno;
	
Tno* constroi(void);
void inserir(Tno* raiz, char *chave, int tamanho);
bool busca(Tno* raiz, char *chave, int tamanho);

void menu();