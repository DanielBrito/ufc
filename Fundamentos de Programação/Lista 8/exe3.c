#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 20

void imprimir(int* vet);
int verifica(int v, int i, int* vet);
int interseccao(int* vetA, int* vetB);

int main(){
	
	int vetorA[MAX];
	int vetorB[MAX];
	int i, j, k=0, valor, inter=0, tamC=0;
	
	srand(time(NULL));
	
	for(i=0; i<MAX; i++){
		
		valor = (rand()%50);
		
		if(verifica(valor, i, vetorA)==1){
			
			vetorA[i] = valor;
		}
		else{
			
			i--;
		}
	}
	
	for(i=0; i<MAX; i++){
		
		valor = (rand()%50);
		
		if(verifica(valor, i, vetorB)==1){
			
			vetorB[i] = valor;
		}
		else{
			
			i--;
		}
	}
	
	printf("VETOR A:    ");
	imprimir(vetorA);
	printf("\n");
	
	printf("VETOR B:    ");
	imprimir(vetorB);
	printf("\n\n");
	
	printf("INTESECCAO: ");
	inter = interseccao(vetorA, vetorB);
	printf("\n\n");
	
	tamC = (2*MAX)-inter;
	
	int* vetorC = calloc(tamC, sizeof(int));
	
	for(i=0; i<MAX; i++){
		
		vetorC[k] = vetorA[i];
		k++;
	}
	
	for(i=0; i<MAX; i++){
			
		if(verifica(vetorB[i], MAX, vetorA)==1){
			
			vetorC[k]=vetorB[i];
			k++;
		}
	}
	
	printf("UNIAO:      ");
	
	for(i=0; i<tamC; i++){
		
		printf("%2d ", vetorC[i]);
	}
	
	free(vetorC);
	
	printf("\n\n");
	
	return 0;
}


void imprimir(int* vet){
	
	int i;
	
	for(i=0; i<MAX; i++){
		
		printf("%2d ", vet[i]);
	}
}

int verifica(int v, int i, int* vet){
	
	int j;
	
	for(j=0; j<i; j++){
		
		if(v==vet[j]){
			
			return 0;
		}
	}
	
	return 1;
}

int interseccao(int* vetA, int* vetB){
	
	int i, j, cont=0;
	
	for(i=0; i<MAX; i++){
		
		for(j=0; j<MAX; j++){
			
			if(vetA[i]==vetB[j]){
				
				printf("%2d ", vetA[i]);
				
				++cont;
			}
		}
	}
	
	return cont;
}
