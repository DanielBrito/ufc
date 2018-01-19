#include<stdio.h>
#include<stdlib.h>

#define TAM 5

struct pessoa{

	char nome[30];
	int idade;
};

typedef struct pessoa Pessoa;

int main(){
	
	Pessoa pessoas[TAM];
	int i;
	
	for(i=0; i<TAM; i++){
		
		printf("Nome: ");
		scanf(" %[^\n]", pessoas[i].nome);
		printf("Idade: ");
		scanf("%d", &pessoas[i].idade);
		
		printf("\n");
	}
	
	printf("\n\n");
	
	printf("MAIORES DE IDADE\n\n");
	
	for(i=0; i<TAM; i++){
		
		if(pessoas[i].idade>18){
			
			printf("Nome: %s\n", pessoas[i].nome);
			printf("Idade: %d\n\n", pessoas[i].idade);
		}
	}
	
	printf("\n");
	
	return 0;	
}
