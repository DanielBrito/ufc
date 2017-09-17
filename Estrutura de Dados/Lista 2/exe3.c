#include<stdio.h>
#include<stdlib.h>

int mdc(int x, int y);

int main(){
	
	int num1, num2;
	
	printf("Digite um numero: ");
	scanf("%d", &num1);
	
	printf("Digite um numero: ");
	scanf("%d", &num2);
	
	printf("\n\n");
	
	printf("O MDC de %d e %d = %d", num1, num2, mdc(num1, num2));
	
	printf("\n\n");
	
	return 0;
}


int mdc(int x, int y){
	
	if(y==0){
		
		return x;
	}
	else{
		
		return mdc(y, x%y);
	}
}
