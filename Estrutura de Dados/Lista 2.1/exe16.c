#include <stdio.h>

int fibo(int n, int a, int b);

int main(){

	int termo;

	printf("Digite a posicao do termo desejado: ");
	scanf("%d", &termo);

	printf("\n");

	printf("O %do termo da sequencia Fibonacci é %d", termo, fibo(termo, 0, 1));
	
	printf("\n");

	return 0;
}

int fibo(int n, int a, int b){

	int c;

	if(n==1){

		return 0;
	}

	if(n==2 || n==3){

		return a+b;
	}

	c = a+b;

	return fibo(n-1, b, c);
}