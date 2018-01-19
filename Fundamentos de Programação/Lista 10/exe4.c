#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define TAM 3

struct habitante{
	
	float salario;
	int idade;
	int filhos;
};

typedef struct habitante Habitante;

void mediaSalario(Habitante* hab);
void mediaNumeroFilhos(Habitante* hab);
void maiorSalario(Habitante* hab);

int main(){
	
	Habitante habitantes[TAM];
	int i;
	
	for(i=0; i<TAM; i++){
		
		printf("Salario: ");
		scanf("%f", &habitantes[i].salario);
		printf("Idade: ");
		scanf("%d", &habitantes[i].idade);
		printf("Numero de filhos: ");
		scanf("%d", &habitantes[i].filhos);
		
		printf("\n");
	}
	
	printf("\nRELATORIO\n\n");
	
	mediaSalario(habitantes); printf("\n");
	mediaNumeroFilhos(habitantes); printf("\n");
	maiorSalario(habitantes);	
	
	printf("\n\n");
	
	return 0;
}


void mediaSalario(Habitante* hab){
	
	float media=0;
	int i;
	
	for(i=0; i<TAM; i++){
		
		media += hab[i].salario;
	}
	
	printf("Media de salario dos habitantes: R$%.2f", (float)media/TAM);
}


void mediaNumeroFilhos(Habitante* hab){
	
	float media=0;
	int i;
	
	for(i=0; i<TAM; i++){
		
		media += hab[i].filhos;
	}
	
	printf("Media do numero de filhos dos habitantes: %.2f", (float)media/TAM);
}

void maiorSalario(Habitante* hab){
	
	float maior = INT_MIN;
	int i;
	
	for(i=0; i<TAM; i++){
		
		if(hab[i].salario>maior){
			
			maior = hab[i].salario;
		}
	}
	
	printf("O maior salario e de R$%.2f", maior);
}
