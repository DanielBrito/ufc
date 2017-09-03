#include<stdio.h>
#include<stdlib.h>

int primo(int t);
int somaPrimos(int* v, int t);

int main(){

	int tam, i;
	int* vetor;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	vetor = (int*) malloc(tam*sizeof(int));

	for(i=0; i<tam; i++){

		printf("Digite um valor: ");
		scanf("%d", &vetor[i]);
	}
	
	printf("\n\nSoma dos primos do vetor: %d", somaPrimos(vetor, tam));

	printf("\n\n");

	return 0;
}


int primo(int num){
	
	int i, cont=0;
	
	for(i=1; i<=num; i++){
				
		if(num%i == 0){
			
			cont++;
		}
	}
	
	if(num==1){
		
		return 0;
	}
	else
	if(cont<3){
		
		return 1; // Numero primo
	}
	else{
		
		return 0; // Numero nao primo
	}
}


int somaPrimos(int* v, int t){

	int i, soma=0;

	for(i=0; i<t; i++){

		if(primo(v[i])==1){

			soma += v[i];
		}
	}

	return soma;
}
