#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int* somaVetor(int* v1, int* v2, int tam){ // Ou int* somaVetor(int v1[], int v2[], int tam)
    
	int i, j;
    int* v3 = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
    
        v3[i] = v1[i] + v2[i];
    }

    return v3;
}


int main(){
	
    int n, i, j, *tam;
    int* vet3;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);
    
    printf("\n");

    int* vet1 = malloc(sizeof(int)*n);
    int* vet2 = malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
    	
        printf("Vetor 1: "); scanf("%d", &vet1[i]);
    }
    
    printf("\n");

    for(j=0; j<n; j++){
    	
        printf("Vetor 2: "); scanf("%d", &vet2[j]);
    }

    vet3 = somaVetor(vet1, vet2, n);

    printf("\n\n");
    
    printf("Soma dos vetores:\n\n");

    for(i=0; i<n; i++){
    	
        printf("%d ", vet3[i]);
    }

    free(vet1);
    free(vet2);
    free(vet3);

    printf("\n\n");

    return 0;
}
