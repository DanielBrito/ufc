#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i, n , termo1=0, termo2=1, soma=0;
	
	printf("Digite a quantidade de termos da serie de Fibonacci: ");
	scanf("%d", &n);
	
	printf("[%d] [%d] ", termo1, termo2);
	
	soma = termo1 + termo2;
	
	for(i=0; i<n-2; i++){
		
		printf("[%d] ", termo1+termo2);
		
		soma += termo1+termo2;
		
		int termoAux = termo2;
		
		termo2 = termo1+termo2;
		termo1 = termoAux;		
	}
	
	printf("\n\nSoma dos termos = %d", soma);
	
	printf("\n\n");
	
	return 0;
}
