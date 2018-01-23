#include<stdio.h>
#include<math.h>

/*  Baseado no exercício:
	
	Mostre que o n-ésimo número da sequência de Fibonacci
	é dado pela fórmula abaixo:
	
	Fn = (pow(((1+sqrt(5))/2), 2) - pow(((1-sqrt(5))/2), n) / sqrt(5)	
*/

int main(){
	
	int p, Fn;
	
	printf("Digite a posicao do e-nesimo numero da sequencia de Finobacci: ");
	scanf("%d", &p);
	
	printf("\n\n");
	
	Fn = (pow(((1+sqrt(5))/2), p) - pow(((1-sqrt(5))/2), p)) / sqrt(5);
	
	printf("Numero na posicao [%d] -> %d.", p, Fn);
	
	printf("\n\n");
	
	return 0;
}


