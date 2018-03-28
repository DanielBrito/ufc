#include <stdio.h>

void converteBin(int n){
	
	int digito;
	
	if(n==0){
		
		return;
	}
	
	converteBin(n/2);
	
	digito = n%2;
	
	printf("%d", digito);
}

int main(){
	
	int numero = 20;
	
	printf("Numero %d em binario:\n\n", numero);
	
	converteBin(numero);

	printf("\n");

	return 0;
}
