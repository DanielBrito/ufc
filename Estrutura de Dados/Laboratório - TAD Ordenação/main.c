#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

void printVetor(int n, int* v);

int main(){

	int* v;
	int i, n, op;

	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &n);

	printf("Entre com os dados do vetor: ");

	v = (int*)malloc(n*sizeof(int));

 	for (i=0; i<n; i++){

 		scanf("%d", &v[i]);
 	}
    
    printf("\nVetor original:\n");
	printVetor(n, v);

	printf("\n1 - Bubble Sort decrescente \n");
	printf("2 - Insertion Sort decrescente \n");
	printf("3 - Selection Sort decrescente \n");
	printf("4 - Bubble Sort crescente \n");
	printf("5 - Insertion Sort crescente \n");
	printf("6 - Selection Sort crescente \n");
	printf("7 - MergeSort Decrescente \n\n");
	printf("- > Entre com a opção desejada: ");
	scanf("%d", &op);

    printf("\nVetor ordenado:\n");

	switch(op){
	  case 1:
	    bubbleSort(n,v);
	    break;

	  case 2:
	    insertionSort(n,v);
	    break;

 	  case 3:
 	    selectionSort(n,v);
 	    break;

 	  case 4:
 	    bubbleSortRec(n,v);
 	    break;

	  case 5:
	    insertionSortRec(n,v);
	    break;

 	  case 6:
 	    selectionSortRec(n,v);
 	    break;
    case 7:
 	    mergeSort(n,v);
 	    break;

	  default:
	    printf("Está opção não está disponível!\n\n");
	    break;
	}

	printVetor(n, v);

 	free(v);

	return 0;
}

void printVetor(int n, int* v){

  int i;

  for(i=0; i<n; i++){

		printf("%d ", v[i]);
	}
    
    printf("\n");
}