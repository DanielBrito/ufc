#include <stdio.h>

int fatorial(int n);

int main(){
	
	int numero;

	printf("Digite um número: ");
	scanf("%d", &numero);

	printf("%d! = %d", numero, fatorial(numero));

	printf("\n");

	return 0;
}

int fatorial(int n){

	if(n==0 || n==1){

		return 1;
	}

	return n * fatorial(n-1);
}