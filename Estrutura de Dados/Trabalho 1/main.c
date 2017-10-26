#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"indice.h"
#include"lista.c"


int main(){

	int qtdEntradas, qtdConsultas, i, pagina;

	char nomeEntrada[100];
	char nomeBuscado[100];

	int qtdTermos = 0;

	Nome* listaNomeEntrada;
	Nome* listaNomeBuscado;

	Indice* listaIndiceNomeBuscado;
	Indice* resultado;

	listaNomeEntrada = criarListaNome();

	printf("\n");

	// system("clear"); /* Opcional */

	printf("QUANTIDADE DE ENTRADAS: ");
	scanf("%d", &qtdEntradas);

	printf("\n");

	if(qtdEntradas>0){

		for(i=0; i<qtdEntradas; i++){

			printf("Página: ");
			scanf("%d", &pagina);

			if(pagina>0){

				printf("Nome: ");
				scanf(" %100[^\n]", nomeEntrada);

				strcpy(nomeEntrada, padronizarNome(nomeEntrada));

				printf("\n");

				listaNomeEntrada = listarNomeEntrada(pagina, listaNomeEntrada, nomeEntrada);
			}
			else{

				printf("Página inválida!\n\n");

				--i;
			}
		}

		printf("\n");

		// system("clear"); /* Opcional */

		printf("QUANTIDADE DE CONSULTAS: ");
		scanf("%d", &qtdConsultas);

		if(qtdConsultas<1){

			free(listaNomeEntrada);

			printf("\n");

			return 0;
		}
		else{

			for(i=0; i<qtdConsultas; i++){

				listaNomeBuscado = criarListaNome();
				resultado = criarListaIndice();

				printf("\n");

				printf("Nome: ");
				scanf(" %100[^\n]", nomeBuscado);

				strcpy(nomeBuscado, padronizarNome(nomeBuscado));

				qtdTermos = contarTermos(nomeBuscado);

				listaNomeBuscado = listarNomeBuscado(listaNomeBuscado, nomeBuscado);

				resultado = buscarNome(listaNomeEntrada, nomeBuscado, listaNomeBuscado, qtdTermos);

				if(resultado!=NULL){

					imprimirListaIndice(resultado);
				}
				else{

					printf("Não há ocorrência\n");
				}
			}

			free(listaNomeEntrada);
			free(listaNomeBuscado);
			free(resultado);
		}
	}

	printf("\n");

	return 0;
}