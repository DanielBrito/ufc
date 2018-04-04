#include <stdio.h>

int somatorio(int n);

int main(){
	
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);

	printf("\n");

	printf("O somatório de 1 a %d = %d", num, somatorio(num));

	printf("\n");

	return 0;
}

int somatorio(int n){

	if(n==1){

		return 1;
	}

	return n + somatorio(n-1);
}