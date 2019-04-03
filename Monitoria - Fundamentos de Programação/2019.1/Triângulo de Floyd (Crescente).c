/* Exercício da lista de Teste das engenharias */

#include<stdio.h>

int main(){
	
	int N, cont=1, i;
	
	printf("Digite o valor de N: ");
	scanf("%d", &N);
	
	while(cont<=N){
		
		for(i=1; i<=cont; i++){
			
			printf("%d", i);
		}
		
		printf("\n");
		cont++;
	}
	
	return 0;
}
