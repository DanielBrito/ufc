#include <stdio.h>
#include <stdlib.h>

void constroiHeap(int n, int *v);
void peneira(int n, int* v);
void heapsort(int n, int* v);
void imprime(int n, int* v);
void troca(int* x, int* y);

int main(){

    int vet[11] = {-1,5,2,9,7,4,3,1,6,8,0};
    int n = 10;

    printf("Vetor original desordenado:\n");
    imprime(n, vet);

    printf("\nVetor em ordem decrescente:\n");
    heapsort(n, vet);
    imprime(n, vet);

    printf("\n");

    return 0;
}

void constroiHeap(int n, int *v){

	int k;

	for(k=1; k<n; k++){

		int f = k+1;

		while(f>1 && v[f/2]>v[f]){

			troca(&v[f], &v[f/2]);
			f /= 2;
		}
	}
}

void peneira(int n, int* v){

	int f = 2;

	while (f<=n) {

		if (f<n && v[f]>v[f+1]){

			++f;
		}
						 
		if (v[f/2] <= v[f]){

			break;
		}
			     	
		troca (&v[f], &v[f/2]);
		f *= 2;
	}
}

void heapsort(int n, int* v){

	int m;

	constroiHeap(n,v);

	for(m=n; m>=2; --m){

		troca(&v[1], &v[m]);
		peneira(m-1,v);
	}
}

void imprime(int n, int* v){

    int i;

    for(i=1; i<=n; i++){

        printf("%d ", v[i]);
    }

    printf("\n");
}

void troca(int* x, int* y){

    int temp = *x;
    *x = *y;
    *y = temp;
}