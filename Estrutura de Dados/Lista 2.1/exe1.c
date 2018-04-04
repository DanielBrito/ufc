#include <stdio.h>

void imprime(int n);

int main(){
	
	int x = 5;

	imprime(x);

	printf("\n");

	return 0;
}

void imprime(int n){

	if(n<0){

		return;
	}

	imprime(n-1);

	printf("%d  ", n);
}