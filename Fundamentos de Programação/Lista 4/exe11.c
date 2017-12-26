#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i, base, expoente, resultado=1;
	
	printf("Digite a base: ");
	scanf("%d", &base);
	printf("Digite o expoente: ");
	scanf("%d", &expoente);
	
	for(i=0; i<expoente; i++){
		
		resultado *= base;
	}
	
	printf("\n%d^%d = %d", base, expoente, resultado);

	printf("\n\n");
	
	return 0;
}
