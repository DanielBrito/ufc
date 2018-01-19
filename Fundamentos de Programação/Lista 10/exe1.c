#include<stdio.h>
#include<stdlib.h>

#define TAM 3

struct aluno{
	
	char matricula[10];
	char nome[30];
	char curso[20];
};

typedef struct aluno Aluno;

int main(){
	
	Aluno alunos[TAM];
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
	
	printf("\n\n");
	
	printf("LISTA DE ALUNOS\n\n");
	
	for(i=0; i<TAM; i++){
		
		printf("Matricula: %s\n", alunos[i].matricula);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Curso: %s\n\n", alunos[i].curso);
	}
	
	printf("\n");
	
	return 0;	
}
