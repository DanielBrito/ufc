/* Programa que copia o conteúdo de um arquivo e cria um novo arquivo com o texto que foi copiado. */

#include<stdio.h>

void copiarTexto(FILE *arquivo1, FILE *arquivo2);

int main(void ){

	FILE *arquivo1 = fopen("/home/danielbrito/arquivo.txt", "r"); // Alterar para o diretório onde o arquivo será lido.

	if(arquivo1 == NULL){

		printf("Nao foi possivel abrir o arquivo.\n\n");

		return 1;
	}

	FILE *arquivo2 = fopen("/home/danielbrito/copia.txt", "w"); // Alterar para o diretório onde o arquivo será salvo.

	copiarTexto(arquivo1, arquivo2);

	fclose(arquivo1);
	fclose(arquivo2);

	return 0;
}


void copiarTexto(FILE *arquivo1, FILE *arquivo2){

	char texto[50];

	while(fgets(texto, 50, arquivo1) != NULL){

		fputs(texto, arquivo2);
	}
}
