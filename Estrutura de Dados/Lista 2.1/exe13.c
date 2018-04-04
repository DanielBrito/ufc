#include <stdio.h>

int somaDig(int x);

int main(){
	
	int num;

	printf("Digite um número: ");
	scanf("%d", &num);

	printf("\n");

	printf("A soma dos digitos do numero é %d", somaDig(num));

	printf("\n");

	return 0;
}

int somaDig(int x){

	if(x>-10 && x<10){

		return x;
	}
	else{

		return x%10 + somaDig(x/10);
	}
}