#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* polinomioA;
	Lista* polinomioB;
	Lista* polinomioC;

	polinomioA = criaPolinomio();
	polinomioB = criaPolinomio();

	polinomioA = insereElementoNoPolinomio(polinomioA, 6, 1);
	polinomioA = insereElementoNoPolinomio(polinomioA, 12, 0);

	polinomioB = insereElementoNoPolinomio(polinomioB, 4, 2);
	polinomioB = insereElementoNoPolinomio(polinomioB, -10, 1);
	polinomioB = insereElementoNoPolinomio(polinomioB, -5, 0);

	printf("Polinomio A: ");

	imprimePolinomio(polinomioA);

	printf("\nPolinomio B: ");

	imprimePolinomio(polinomioB);

	printf("\n\nSoma dos Polinomios: ");

	if(ordemDosPolinomios(polinomioA, polinomioB)==1){

			polinomioC = somaPolinomios(polinomioA, polinomioB);
	}
	else{

			polinomioC = somaPolinomios(polinomioB, polinomioA);
	}

	imprimePolinomio(polinomioC);

	printf("\n");

	liberaPolinomio(polinomioA);
	liberaPolinomio(polinomioB);
	liberaPolinomio(polinomioC);

	return 0;
}