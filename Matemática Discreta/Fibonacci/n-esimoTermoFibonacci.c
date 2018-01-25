#include<stdio.h>
#include<math.h>

/*  Baseado no exercício:
	
	Mostre que o n-ésimo termo da sequência de Fibonacci é dado pela Fórmula de Binet.
	
	Mais informacoes: http://www.matematicadidatica.com.br/SequenciaFibonacci.aspx
*/

int arredondaNumero(float num);

int main(){
	
	int p; 	
	float Fn;
	
	printf("SEQUENCIA DE FIBONACCI\n\n");
	
	while(1){
		
		printf("Digite a posicao do n-esimo termo: ");
		scanf("%d", &p);
		
		printf("\n");
		
		Fn = (pow(((1+sqrt(5))/2), p) - pow(((1-sqrt(5))/2), p)) / sqrt(5);
		
		printf("Termo da posicao [%d] -> %d.", p, arredondaNumero(Fn));
		
		printf("\n\n");
	}
	
	return 0;
}


int arredondaNumero(float num){
	
	return (num>=0) ? (int)(num+0.5) : (int)(num-0.5);
}
