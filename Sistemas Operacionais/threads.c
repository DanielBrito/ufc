/*

ATIVIDADE: Desenvolver um algoritmo onde o processo principal cria duas threads,
uma responsável por receber um texto digitado pelo usuário, e outra responsável
por escrever o texto digitado em um arquivo e salvá-lo.

*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int fd[2];

void* leitura(void *arg){

	char str[100];

	while(1){

		printf("THREAD DE LEITURA - Digite seu texto: ");
		scanf(" %[^\n]", str);

		write(fd[1], str, sizeof(str)+1);

		break;
	}
}


void* escrita(void *arg){

	char buffer[100];

   	while(1)
   	{
      	read(fd[0], buffer, sizeof(buffer));

		printf("THREAD DE ESCRITA - String recebida: %s\n", buffer);

		printf("Salvando o texto em um arquivo...\n");

		sleep(2);

		FILE *arquivo;

		arquivo = fopen("texto.txt", "w");

		if(arquivo == NULL){

			printf("Erro ao criar o arquivo!\n");
		}
		else{

			fprintf(arquivo, "%s\n", buffer);
		}

		fclose(arquivo);

		printf("Arquivo salvo com sucesso!\n");

		break;
   	}
}


int main(void){

	pthread_t threadLeitura, threadEscrita;

	pipe(fd);

	pthread_create(&threadLeitura, NULL, leitura, NULL);
	pthread_create(&threadEscrita, NULL, escrita, NULL);

   	pthread_join(threadLeitura,NULL);
   	pthread_join(threadEscrita,NULL);

    return 0;
}