/* Exercício da lista de Teste das engenharias */

#include<stdio.h>

int main(){
	
	int N, cont=1, i;
	
	printf("Digite o valor de N: ");
	scanf("%d", &N);
	
	while(cont<=N){

		for(i=1; i<=cont; i++){
			
			if((cont%2==1 && i%2==1) || (cont%2==0 && i%2==0)){
				
				printf("1");
			}
			else{
				
				printf("0");
			}
		}
		
		printf("\n");
		cont++;
	}
	
	return 0;
}
