#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5

struct aluno{
	
	char matricula[10];
	char nome[30];
	char curso[20];
};

typedef struct aluno Aluno;

void buscaNome(Aluno* alunos, char* str);

int main(){
	
	Aluno alunos[TAM];
	char nomeBuscado[20];
	int i;
	
	for(i=0; i<TAM; i++){
		
		printf("Matricula: ");
		scanf("%s", alunos[i].matricula);
		printf("Nome: ");
		scanf(" %[^\n]", alunos[i].nome);
		printf("Curso: ");
		scanf(" %[^\n]", alunos[i].curso);
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("Digite o nome buscado: ");
	scanf("%s", nomeBuscado);
	
	printf("\n");
	
	buscaNome(alunos, nomeBuscado);	
	
	printf("\n\n");
	
	return 0;
}


void buscaNome(Aluno* alunos, char* str){
	
	int i, resultado=0;
	
	for(i=0; i<TAM; i++){
		
		if(strstr(alunos[i].nome, str)!=NULL){
			
			printf("Matricula: %s\n", alunos[i].matricula);
			printf("Nome: %s\n", alunos[i].nome);
			printf("Curso: %s\n\n", alunos[i].curso);
			
			resultado++;
		}
	}
	
	if(resultado==0){
		
		printf("Nome nao encontrado.");
	}
}
