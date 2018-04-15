#include <stdio.h>
#include <stdlib.h>

void decimalHexa(int n);

int main(){
	
	int num;

	printf("Digite um valor: ");
	scanf("%d", &num);

	printf("%d em hexadecimal: ", num);

	decimalHexa(num);

	printf("\n");

	return 0;
}

void decimalHexa(int n){

	int digito;

	if(n==0){

		return;
	}

	decimalHexa(n/16);

	digito = n%16;

	if(digito==10)
		printf("A");
	else if(digito==11)
		printf("B");
	else if(digito==12)
		printf("C");
	else if(digito==13)
		printf("D");
	else if(digito==14)
		printf("E");
	else if(digito==15)
		printf("F");
	else
		printf("%d", digito);
}