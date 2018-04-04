#include <stdio.h>

int expo(int k, int n);

int main(){

	int base, expoente;

	printf("Digite a base e o expoente: ");
	scanf("%d %d", &base, &expoente);
	
	printf("%d^%d = %d", base, expoente, expo(base, expoente));

	printf("\n");

	return 0;
}

int expo(int k, int n){

	if(n==0){

		return 1;
	}

	if(n==1){

		return k;
	}

	return k * expo(k, n-1);
}