#include<stdio.h>
#include<stdlib.h>
#include"filaLista.h"

int main(){

	Fila2* f = fila2_cria();

	fila2_insere_ini(f, 13);

	float valor = fila2_retira_fim(f);

	printf("VALOR: %.2f\n", valor);

	fila2_retira_ini(f);
}