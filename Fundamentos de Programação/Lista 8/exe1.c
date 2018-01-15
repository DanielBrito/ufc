#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define TAM 50

void maior_menor(int* vetor, int tam);

int main(){
	
    int i;
    int numeros[TAM];

    srand(time(NULL));

    for (i=0; i<TAM; i++){
    	
        numeros[i] = (rand()%500)-250;
    }

    maior_menor(numeros, TAM);
    
    printf("\n\n");

    return 0;
}

void maior_menor(int* vetor, int tam){
	
    int menor=INT_MAX, maior=INT_MIN, i;

    for(i=0; i<tam; i++){
    	
        if(vetor[i]<menor){
        	
            menor = vetor[i];
        }
    }

    for(i=0; i<tam; i++){
    	
        if(vetor[i]>maior){
        	
            maior = vetor[i];
        }
    }

    printf("O maior numero e %d\n", maior);
    printf("O menor numero e %d\n", menor);
}
