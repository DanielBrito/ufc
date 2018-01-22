#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void constroi(int* v, int t, int i);
void peneira(int* v, int t);
void heapsortRecursivo(int* v, int t);
void troca(int* x, int* y);


int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	heapsortRecursivo(vetor, TAM);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void heapsortRecursivo(int* v, int t){

    int i;

    peneira(v, t);

    for(i=t-1; i>=0; i--){

        troca(&v[0], &v[i]);

        int heapTam = i;

        constroi(v, heapTam, 0);
    }
}


void constroi(int* v, int t, int i){

    int max = i;
    int esq = 2*i+1;
    int dir = 2*i+2;

    if(esq<t && v[esq]>v[max]){

        max = esq;
    }

    if(dir<t && v[dir]>v[max]){

        max = dir;
    }

    if(max!=i){

        troca(&v[i], &v[max]);

        constroi(v, t, max);
    }
}


void peneira(int* v, int t){

    int i;

    for(i=(t/2)-1; i>=0; i--){

        constroi(v, t, i);
    }
}


void troca(int* x, int* y){

    int temp = *x;
    *x = *y;
    *y = temp;
}