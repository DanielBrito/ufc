#include <stdio.h>

void imprime(int n){

	if(n<0){

		return;
	}

	if(n%2==0){

		printf("%d  ", n);
	}

	imprime(n-1);
}

int main(){
	
	int x = 10;
	
	printf("Numeros pares de 0 a %d em ordem decrescente:\n\n", x);

	imprime(x);

	printf("\n");

	return 0;
}
