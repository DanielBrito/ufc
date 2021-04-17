#include<stdio.h>

int main(){
	
	int dias, anos, meses, resto;
	
	printf("Digite sua idade em dias: ");
	scanf("%d", &dias);
	
	anos = dias/365; // Divisao inteira para sabermos quantos anos (de 365 dias) podem ser formados com x dias
	resto = dias%365; // O que sobrar da divisão anterior, utilizaremos para calcular os meses
	meses = resto/30; // Divisao inteira para sabermos quantos meses (de 30 dias) cabe no resto da divisão anterior
	dias = resto%30; // O que sobrar da divisão anterior, sabemos que são os dias remanescentes
	
	printf("\nSua idade e dada por:\n\n");
	printf("%d ano(s)\n", anos);
	printf("%d mes(es)\n", meses);
	printf("%d dia(s)\n", dias);

	return 0;	
}
