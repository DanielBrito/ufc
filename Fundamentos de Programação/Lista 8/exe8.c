#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define TAM 50

int main(){
	
    int i, num, cont=0;
    int numeros[TAM];

    srand(time(NULL));

    for (i=0; i<TAM; i++){
    	
        numeros[i] = (rand()%100);
    }
    
    printf("Vetor de numeros aleatorios\n\n");
    
    for (i=0; i<TAM; i++){
    	
        printf("%d ", numeros[i]);
    }
    
    printf("\n\n");
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    
    for (i=0; i<TAM; i++){
    	
        if(numeros[i]==num){
        	
        	cont++;
		}
    }
    
	printf("\n\nO numero %d aparece %d vez(es) no vetor.", num, cont);
    
    printf("\n\n");

    return 0;
}
