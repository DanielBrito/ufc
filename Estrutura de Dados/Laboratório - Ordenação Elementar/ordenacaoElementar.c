#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int n);
void insertionSortRecursivo(int* v, int n);

void selectionSort(int* v, int n);
void selectionSortRecursivo(int* v, int n);

void bubbleSort(int* v, int n);
void bubbleSortOtimizado(int* v, int n);
void bubbleSortRecursivo(int* v, int n);

int main(){
	
	int vetor[5] = {2,5,4,3,0};
	int i;

	for(i=0; i<5; i++){

		printf("%d ", vetor[i]);
	}

	bubbleSortRecursivo(vetor, 5);

	printf("-> ");
	
	for(i=0; i<5; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n");

	return 0;
}

void insertionSort(int* v, int n){

	int i, j, x;

	for(j=1; j<n; j++){

		x = v[j];

		for(i=j-1; i>=0 && v[i]>x; i--){

			v[i+1] = v[i];
		}

		v[i+1] = x;
	}
}

void insertionSortRecursivo(int* v, int n){

	int i, j, x;

	if(n>1){

		insertionSortRecursivo(v, n-1);

		x = v[n-1];
	
		for(j=n-2; j>=0; j--){

			if(v[j]<x){

				break;
			}

			v[j+1] = v[j];
		}

		v[j+1] = x;
	}
}

void selectionSort(int* v, int n){

	int i, x, j, min;

	for(i=0; i<n; i++){

		min = i;

		for(j=i+1; j<n; j++){

			if(v[j]<v[min]){

				min = j;
			}
		}

		x = v[min];
		v[min] = v[i];
		v[i] = x;
	}
}

void selectionSortRecursivo(int* v, int n){

	int i, x, j, min;

	if(n>1){

		min = 0;

		for(j=1; j<n; j++){

			if(v[j]<v[min]){

				min = j;
			}
		}

		x = v[min];
		v[min] = v[0];
		v[0] = x;

		selectionSortRecursivo(v+1, n-1);
	}
}

void bubbleSort(int* v, int n){

	int k, i, j, x;

	k = n;

	for(i=0; i<n; i++){

		for(j=1; j<k; j++){

			if(v[j-1]>v[j]){

				x = v[j-1];
				v[j-1] = v[j];
				v[j] = x;
			}
		}

		k--;
	}
}

void bubbleSortOtimizado(int* v, int n){

	int i, j;

	for(i=n-1; i>0; i--){

		int troca = 0;

		for(j=0; j<i; j++){

			if(v[j]>v[j+1]){

				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				troca=1;
			}
		}

		if(troca==0){

			return;
		}
	}
}

void bubbleSortRecursivo(int* v, int n){

    int i, j, aux;

    if(n>1){

    	for(j=0; j<n-1; j++){

        	if(v[j]>v[j+1]){

          		aux = v[j];
          		v[j] = v[j+1];
          		v[j+1]=aux;
        	}

        	bubbleSortRecursivo(v, n-1);
     	}
    }
}
