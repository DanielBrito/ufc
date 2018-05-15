#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

/*

Dada uma lista de caracteres formada por uma sequencia alternada de numeros e letras, 
construa uma funcao que retorne uma lista na qual os numeros sao mantidos na ordem 
original e as letras sao mantidas na ordem inversa.

Os numeros devem ser mostrados primeiro, seguido das letras.

*/

Lista* transformaLista(Lista* l);

int main(){

	Lista* l = listaCria();
	Lista* c = listaCria();

	l = listaInsere(l, '7');
	l = listaInsere(l, 'm');
	l = listaInsere(l, '3');
	l = listaInsere(l, 'c');
	l = listaInsere(l, '9');
	l = listaInsere(l, 'h');
	l = listaInsere(l, '5');
	l = listaInsere(l, 'f');
	l = listaInsere(l, '6');
	
	printf("Lista Original:\n");
	listaImprime(l);

	printf("\n\n");

	c = transformaLista(l);

	printf("Lista Transformada:\n");
	listaImprime(c);

	printf("\n");

	listaLibera(l);
	listaLibera(c);

	return 0;
}

Lista* transformaLista(Lista* l){

	Lista* result = listaCria();
	Lista* p = l;
	char c;

	Fila* numeros = filaCria();
	Pilha* letras = p_cria();

	while(p!=NULL){

		c = listaRetornaInicio(p);

		p = listaRemoveInicio(p);

		if(c >= '0' && c <= '9'){

			filaInsere(numeros, c);
		}

		if(c >= 'a' && c <= 'z'){

			p_push(letras, c);
		}
	}

	while(!filaVazia(numeros)){

		c = filaRetira(numeros);

		result = listaInsere(result, c);
	}

	while(!p_vazia(letras)){

		c = p_pop(letras);

		result = listaInsere(result, c);
	}

	p_libera(letras);
	filaLibera(numeros);

	return result;
}
