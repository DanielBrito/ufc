#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"lista.h"
#include"indice.h"
#include"indice.c"


Nome* criarListaNome(void){

	return NULL;
}


Nome* listarNomeEntrada(int pg, Nome* n, char* str){

	int i=0, j;

	char *vet[100], vetAux[100];

	char *strAux;

	strcpy(vetAux, str);

	vetAux[strlen(vetAux)] = '\0';

	strAux = strtok(vetAux, " ");

	vet[i] = (char*)malloc(sizeof(char)*100);

	strcpy(vet[i], strAux);

	i++;

	do{

		strAux = strtok(NULL, " ");

		if(strAux != NULL){

			vet[i] = (char*)malloc(sizeof(char)*100);

			strcpy(vet[i++], strAux);
		}
	
	}while(strAux != NULL);


	for(j=0; j<i; j++){

		n = inserirNome(pg, n, vet[j]);
	}

	return n;
}


Nome* inserirNome(int pg, Nome* n, char* str){

	Nome* aux;

	Indice* novoIndice;
	novoIndice = criarListaIndice();

	for(aux=n; aux!=NULL; aux=aux->proxNome){

		if(strcmp(aux->texto, str)==0){
			
			aux->id = inserirIndice(aux->id, pg);

			return n;
		}
	}
	
	Nome* novoNome;
	novoNome = (Nome*)malloc(sizeof(Nome));

	novoNome->id = inserirIndice(novoIndice, pg);

	strcpy(novoNome->texto, str);
	novoNome->proxNome = n;

	return novoNome;
}


Nome* listarNomeBuscado(Nome* n, char* str){

	int i=0, j;

	char *vet[100], vetAux[100];

	char *strAux;

	strcpy(vetAux, str);

	vetAux[strlen(vetAux)] = '\0';

	strAux = strtok(vetAux, " ");

	vet[i] = (char*)malloc(sizeof(char)*100);

	strcpy(vet[i], strAux);

	i++;

	do{

		strAux = strtok(NULL, " ");

		if(strAux != NULL){

			vet[i] = (char*)malloc(sizeof(char)*100);

			strcpy(vet[i++], strAux);
		}
	
	}while(strAux != NULL);


	for(j=0; j<i; j++){

		n = inserirNomeBuscado(n, vet[j]);
	}

	return n;
}


Nome* inserirNomeBuscado(Nome* n, char* str){

	Nome* novoNome;
	novoNome = (Nome*)malloc(sizeof(Nome));

	strcpy(novoNome->texto, str);
	novoNome->proxNome = n;

	return novoNome;
}


int contarTermos(char* str){

	int i=0, j;
	int qtdTermos = 0;

	char cmd[100], *vec[256];

	char *strAux;

	strcpy(cmd, str);

	cmd[strlen(cmd)] = '\0';

	strAux = strtok(cmd, " ");

	vec[i] = (char*)malloc(sizeof(char)*256);

	strcpy(vec[i], strAux);

	i++;

	do{

		strAux = strtok(NULL, " ");

		if(strAux != NULL){

			vec[i] = (char*)malloc(sizeof(char)*256);

			strcpy(vec[i++], strAux);
		}
	
	}while(strAux != NULL);


	for(j=0; j<i; j++){

		++qtdTermos;
	}

	return qtdTermos;
}


char* padronizarNome(char* str){

	// Caracteres acentuados mais comuns em nomes no Brasil:

	char maiusculas[]="ÁÃÂÇÉÊÈÍÓÔÚ";
	char minusculas[]="áãâçéêèíóôú";

	int i, j;

	for(i=0; i<strlen(str); i++){

		for(j=0; j<strlen(maiusculas); j++){

			minusculas[j];

			if(str[i]!=maiusculas[j]){

				str[i] = tolower(str[i]);
			}
			else{

				str[i] = minusculas[j];
			}
		}
	}

	return str;
}


/*

// FUNÇÕES DE TESTE:

void imprimirNome(Nome* n){

	Nome* p;

	for(p=n; p!=NULL; p=p->proxNome){

		printf("%s\n", p->texto);
	}	
}


void imprimirUmNome(Nome* n){

	Nome* p = n;

	printf("%s\n", p->texto);
}

*/