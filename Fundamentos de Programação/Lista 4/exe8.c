#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
	
	int i, n, maior=INT_MIN;
	
	for(i=0; i<5; i++){
		
		printf("Digite um valor: ");
		scanf("%d", &n);
		
		if(n>maior){
			
			maior = n;
		}
	}
	
	printf("\nO maior valor digitado = %d", maior);

	printf("\n\n");
	
	return 0;
}
