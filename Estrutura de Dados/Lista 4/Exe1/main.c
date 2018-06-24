#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){

	Pilha* p = inicializaPilhas();
	int i;

	for(i=1; i<=49; i++){

		empilhaP1(p, i);
	}

	for(i=1; i<=31; i++){

		empilhaP2(p, i);
	}

	printf("\n");

	libera(p);

	return 0;
}