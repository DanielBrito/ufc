#include <stdio.h>

int soma(int* v, int n, int x);

int main(){
	
	int vetor1[5] = {4,9,1,7,3};
	int vetor2[5] = {4,9,2,7,5};
	int i, n = 10;

	for(i=0; i<5; i++){

		printf("[%d] ", vetor1[i]);
	}

	printf("\n");

	if(soma(vetor1, 5, n)){

		printf("Existem dois elementos cuja soma é igual a %d no vetor", n);
	}
	else{

		printf("Não existem dois elementos cuja soma é igual a %d no vetor", n);
	}

	printf("\n\n");

	for(i=0; i<5; i++){

		printf("[%d] ", vetor2[i]);
	}

	printf("\n");

	if(soma(vetor2, 5, n)){

		printf("Existem dois elementos cuja soma é igual a %d no vetor", n);
	}
	else{

		printf("Não existem dois elementos cuja soma é igual a %d no vetor", n);
	}

	printf("\n");

	return 0;
}


int soma(int* v, int n, int x){

	int i;

	if(n==1){

		return 0;
	}

	for(i=0; i<n; i++){

		if(v[i]+v[i+1] == x){

			return 1;
		}
	}

	soma(v+1, n-1, x);
}