/*

ATIVIDADE: Implemente um comunicação interprocesso envolvendo 2 processos: 
o produtor deverá enviar strings digitadas pelo usuário ao consumidor que, 
por sua vez, deverá salvá-las em um arquivo chamado “texto.txt”.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

	pid_t pid;
	int fd[2];
	char string[100];
	char buffer[100];

	if(pipe(fd)<0){

        perror("pipe");

        return -1 ;
    }

	if((pid = fork()) == -1){

		perror("fork");

		exit(1);
	}

	if(pid==0){

		// PROCESSO FILHO:

		close(fd[1]);

		read(fd[0], buffer, sizeof(buffer));

		printf("PROCESSO FILHO - String digitada: %s\n", buffer);

		printf("Salvando o texto em um arquivo...\n");

		sleep(2);

		FILE *arquivo;

		char url[] = "texto.txt";

		arquivo = fopen(url, "w");

		if(arquivo == NULL){

			printf("Erro ao criar o arquivo!\n");
		}
		else{

			fprintf(arquivo, "%s\n", buffer);
		}

		fclose(arquivo);

		printf("\nArquivo salvo com sucesso!\n");

		exit(0);
	}
	else{

		// PROCESSO PAI:

		close(fd[0]);

		printf("PROCESSO PAI - Digite seu texto: ");
		scanf(" %[^\n]", string);

		write(fd[1], string, sizeof(string)+1);

		exit(0);

	}

	return 0;
}