#include<stdio.h>

/*
	Faca um programa que receba dois numeros digitados pelo usuario,
	calcule e mostre o resultado da divisao do primeiro pelo segundo.
	Sabe-se que, em uma divisao, o segundo numero nao pode ser zero.
	Entao, se o segundo numero informado pelo usuario for zero, deve-se
	mostrar uma mensagem indicando que a divisao nao podera ser efetuada.
*/

int main(){
	
	float num1, num2;
	
	printf("Digite o valor do dividendo: ");
	scanf("%f", &num1);
	
	printf("Digite o valor do divisor: ");
	scanf("%f", &num2);
	
	printf("\n");
	
	if(num2==0){
		
		printf("Nao existe divisao por 0.");
	}
	else{
		
		printf("%.2f dividido por %.2f = %.2f", num1, num2, num1/num2);
	}
	
	printf("\n\n");
	
	return 0;
}
