#include <stdio.h>

void imprimePares(int n);

int main(){
	
	int num;

	printf("Digite um valor: ");
	scanf("%d", &num);

	printf("\n");

	imprimePares(num);

	printf("\n");

	return 0;
}


void imprimePares(int n){

	if(n<0){

		return;
	}

	if(n%2==0){

		printf("%d\n", n);
	}

	imprimePares(n-1);
}