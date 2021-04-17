/* Exercício da lista de Teste das engenharias */

#include<stdio.h>

int main(){
	
	int N, cont=1, i;
	
	printf("Digite o valor de N: "); 
	scanf("%d", &N); // Variável que será utilizada para definir a quantidade de números na última linha, bem como a altura do triângulo
	
	while(cont<=N){ // Laço para verificar a quantidade de linhas do triângulo
		
		for(i=1; i<=cont; i++){ // Laço para imprimir os elementos de uma determinada linha
			
			printf("%d", i);
		}
		
		printf("\n");
		cont++; // Contador para fazer o controle da quantidade de elementos em uma linha
	}
	
	return 0;
}
