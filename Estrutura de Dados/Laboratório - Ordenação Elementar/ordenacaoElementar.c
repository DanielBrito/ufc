#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int n);
void insertionSortRecursivo(int* v, int n);

void selectioSort(int* v, int n);
void selectioSortRecursivo(int* v, int n);

void bubbleSort(int* v, int n);
void bubbleSortRecursivo(int* v, int n);

int main(){
	
	int vetor[5] = {6,2,9,7,4};
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

void selectioSort(int* v, int n){

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

void selectioSortRecursivo(int* v, int n){

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

		selectioSortRecursivo(v+1, n-1);
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

void bubbleSortRecursivo(int* v, int n){

	int k, i, j, x;

	if(n>1){

		k = n;

		for(i=0; i<n; i++){

			for(j=0; j<k; j++){

				if(v[j]>v[j+1]){

					x = v[j];
					v[j] = v[j+1];
					v[j+1] = x;
				}
			}
		}

		bubbleSortRecursivo(v, n-1);
	}	
}