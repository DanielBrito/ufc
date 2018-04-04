#include <stdio.h>

int pertence(int* v, int n, int x);

int main(){
	
	int vetor[5] = {1,2,3,4,5};
	int num, i;

	printf("Digite um valor: ");
	scanf("%d", &num);

	printf("\n");

	for(i=0; i<5; i++){

		printf("[%d] ", vetor[i]);
	}

	printf("\n");

	if(pertence(vetor, 5, num)){

		printf("O numero %d pertence ao vetor", num);
	}
	else{

		printf("O numero %d nao pertence ao vetor", num);
	}

	printf("\n");

	return 0;
}

int pertence(int* v, int n, int x){

	if(n==1){

		if(v[0]==x){

			return 1;
		}
		else{

			return 0;
		}
	}

	if(v[0]==x){

		return 1;
	}
	else{

		pertence(v+1, n-1, x);
	}
}