#include <stdio.h>

int fatQuad(int num);
int fatorial(int n);

int main(){
	
	int num;

	printf("Digite um número: ");
	scanf("%d", &num);

	printf("\n");

	printf("%d!! = %d", num, fatQuad(num));

	printf("\n");

	return 0;
}

int fatorial(int n){

	if(n==0 || n==1){

		return 1;
	}

	return n * fatorial(n-1);
}

int fatQuad(int num){

	return (fatorial(2*num))/(fatorial(num));
}