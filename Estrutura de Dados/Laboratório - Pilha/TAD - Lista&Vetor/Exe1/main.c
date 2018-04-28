#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){

	Pilha* p = inicializaPilha();
	Pilha* c = inicializaPilha();
	Pilha* s = inicializaPilha();

	empilha(p,'a');
	empilha(p,'b');
	empilha(p,'c');
	empilha(p,'d');

	printf("PILHA ORIGINAL:\n");
	imprimePilha(p);

	printf("IMPRIME REVERSA:\n");
	imprimeReversa(p);

	printf("PILHA ORIGINAL:\n");
	imprimePilha(p);

	c = copiaPilhaV(p); /* c = copiaPilhaL(p); */

	printf("COPIA DA ORIGINAL:\n");
	imprimePilha(p);

	p = invertePilhaV(p); /* p = invertePilhaL(p); */

	printf("PILHA INVERTIDA:\n");
	imprimePilha(p);

	printf("NOVA PILHA:\n");
	imprimePilha(p);

	c = copiaPilhaV(p); /* c = copiaPilhaL(L); */

	printf("COPIA DA NOVA PILHA:\n");
	imprimePilha(p);

	printf("PILHA:\n");
	imprimePilha(p);

	int v = palindrome(p);

	printf("PALINDROME?\n");
	v == 1 ? printf("Sim\n\n") : printf("Não\n\n");

	printf("PILHA:\n");
	imprimePilha(p);

	elimina(p, 'b');
	elimina(p, 'z');

	printf("APÓS REMOVER ELEMENTO:\n");
	imprimePilha(p);

	char str[30];
	int i=0;

	printf("DIGITE UMA STRING:\n");
	scanf("%[^\n]", str);

	for(i=0; i<strlen(str); i++){

		empilha(s, str[i]);
	}

	printf("\nPILHA DA STRING:\n");
	imprimePilha(s);

	maiusculoMinusculo(s);

	printf("\n");

	libera(p);
	libera(c);
	libera(s);
	
	return 0;
}