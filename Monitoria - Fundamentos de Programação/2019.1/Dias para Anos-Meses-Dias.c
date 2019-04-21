#include<stdio.h>

int main(){
	
	int dias, anos, meses, resto;
	
	printf("Digite sua idade em dias: ");
	scanf("%d", &dias);
	
	anos = dias/365;
	resto = dias%365;
	meses = resto/30;
	dias = resto%30;
	
	printf("\nSua idade e dada por:\n\n");
	printf("%d ano(s)\n", anos);
	printf("%d mes(es)\n", meses);
	printf("%d dia(s)\n", dias);

	return 0;	
}
