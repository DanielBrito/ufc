#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){

	Pilha* p1 = inicializaPilha1();
	Pilha* p2 = inicializaPilha2();
	int i;

	for(i=1; i<=49; i++){

		empilhaP1(p1, p2, i);
	}

	for(i=1; i<=31; i++){

		empilhaP2(p1, p2, i);
	}

	printf("\n");

	libera(p1);
	libera(p2);

	return 0;
}