#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n, i, soma=0;
	
	printf("Digite um numero: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		
		soma += i;
	}
	
	printf("A soma dos numeros de 1 ate %d = %d", n, soma);

	printf("\n\n");
	
	return 0;
}
