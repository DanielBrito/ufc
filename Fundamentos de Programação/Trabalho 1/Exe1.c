#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculaMediaAritmetica();
void calculaMediaPonderada();

int main(){

	setlocale(LC_ALL,"");

	int opcao;
	
	system("cls");
	
	printf("\t\t****************************************\n");
	printf("\t\t********** CÁLCULO DE MÉDIAS ***********\n");
	printf("\t\t****************************************\n");
	
	printf("\n\n");
	
	printf("1 - MÉDIA ARITMÉTICA\n");
	printf("2 - MÉDIA PONDERADA\n");
	printf("3 - SAIR\n\n");
	printf("OPÇÃO >> ");
	scanf("%d", &opcao);
	
	switch(opcao){
		
		case 1: calculaMediaAritmetica();
		
		case 2: calculaMediaPonderada();
		
		case 3: exit(0);
		
		default: printf("\n\nOpção inválida!\n\n");
		
		system("PAUSE");
		
		main();
	}
}

void calculaMediaAritmetica(){
	
	system("cls");
	
	printf("\t\t****************************************\n");
	printf("\t\t*********** MÉDIA ARITMÉTICA ***********\n");
	printf("\t\t****************************************\n");
	
	printf("\n\n");
	
	float media, nota1, nota2;
	
	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	
	printf("\n");
	
	media = (nota1 + nota2)/2;

	printf("Média Aritmética: %.2f\n\n", media);

	system("PAUSE");
	
	main();
}

void calculaMediaPonderada(){
	
	system("cls");
	
	printf("\t\t****************************************\n");
	printf("\t\t*********** MÉDIA PONDERADA ************\n");
	printf("\t\t****************************************\n");
	
	printf("\n\n");
		
	float n1,n2,n3,somapesos;
	float peso1,peso2,peso3,mediaponderada,valormedia;

	printf("Digite a primeira nota : ");
	scanf("%f", &n1);

	printf("Peso (Nota1): ");
	scanf("%f", &peso1);
	
	printf("\n");

	printf("Digite a segunda nota : ");
	scanf("%f", &n2);
	
	printf("Peso (Nota2): ");
	scanf("%f", &peso2);
	
	printf("\n");
	
	printf("\nDigite a terceira nota : ");
	scanf("%f", &n3);
	
	printf("Peso (Nota3): ");
	scanf("%f", &peso3);

	somapesos = peso1 + peso2 + peso3;
	
	valormedia = (n1*peso1)+(n2*peso2)+(n3*peso3);
	
	mediaponderada  = valormedia/somapesos;

	printf("\n");
	
	printf("Média Ponderada: %.2f\n\n", mediaponderada);
	
	system("PAUSE");

	main();
}
